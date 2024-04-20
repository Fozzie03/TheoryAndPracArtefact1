struct memory{
    int size;
    char stack[256];
};

// STACK FUNCTIONS

//Initialize stack
int stackInit(struct memory *stack){
    printf("\nInitializing Stack");
    stack -> size = 1;
    stack -> stack[0] = '$';

    return 0;
}

//Push Value to Stack
int push(struct memory *stack, char value){
    printf("\n  Pushing %c", value);
    stack->stack[stack->size++] = value;

    return 0;
}

//Pop Value off the stack
char pop(struct memory *stack){
    stack -> size--;
    char value = stack->stack[stack->size];
    printf("\n  Popping %c", value);
    stack-> stack[stack -> size] = NULL;

    return value;
}

//Read stack
char peek(struct memory *stack){
    
    printf("\n  Peeking %c", stack -> stack[stack -> size-1]);
    return stack -> stack[stack -> size-1];
}

// STACK FUNCTIONS END


int pdaStateZero(char input[]){
    //INITIALIZE THE PDA
    //Keep track of position in the string


    
    printf("\nState Zero");

    int pos = 0;
    //Initialize Stack
    struct memory stack;
    stackInit(&stack);

    return pdaStateOne(input, stack, pos);
}

int pdaStateOne(char input[], struct memory stack, int pos){
    printf("\nState One");

    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'a') {
            push(&stack, 'x');
            return pdaStateOne(input, stack, ++pos);
        } 
        
        else if (input[pos] == 'b'){
            pop(&stack);
            if (pdaStateTwo(input, stack, ++pos) == 1) return 1;
            push(&stack, 'x');

            return pdaStateFour(input, stack, pos);
        } 
        
        else return -1;

    } else return 0;
}

int pdaStateTwo(char input[], struct memory stack, int pos){
    printf("\nState Two");
    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'b'){
            pop(&stack);
            return pdaStateTwo(input, stack, ++pos);
        } else if (input[pos] == 'c'){
            return pdaStateThree(input, stack, ++pos);
        } else return -1;
        
    } else return 0;
}

int pdaStateThree(char input[], struct memory stack, int pos){
    printf("\nState Three");
    if(pos < 265 && input[pos] != NULL){    
        if(input[pos] == 'c'){
            return pdaStateThree(input, stack, ++pos);
        } else return -1;

    } else return pdaStateSix(input, stack, pos);
}

int pdaStateFour(char input[], struct memory stack, int pos){
    printf("\nState Four");
    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'b'){
            return pdaStateFour(input, stack, ++pos);
        } else if(input[pos] == 'c'){
            if(peek(&stack) != 'x') return 0;
            pop(&stack);
            return pdaStateFive(input, stack, ++pos);
        } else return -1;

    } else return 0;
}

int pdaStateFive(char input[], struct memory stack, int pos){
    printf("\nState Five");
    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'c'){
            if(peek(&stack) != 'x') return 0;
            pop(&stack);
            return pdaStateFive(input, stack, ++pos);
        } else return -1;
    } else return pdaStateSix(input, stack, pos);

}

int pdaStateSix(char input[], struct memory stack, int pos){
    printf("\nState Six");
    if(peek(&stack) != '$') return 0;
    else return 1;
}