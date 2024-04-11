struct memory{
    int size;
    char stack[256];
};

int stackInit(struct memory *stack){
    printf("\nInitializing Stack");
    stack -> size = 1;
    stack -> stack[0] = '$';

    return 0;
}

int push(struct memory *stack, char value){
    printf("\n  Pushing %c", value);
    stack->stack[stack->size++] = value;

    return 0;
}
char pop(struct memory *stack){
    stack -> size--;
    char value = stack->stack[stack->size];
    printf("\n  Popping %c", value);
    stack-> stack[stack -> size] = NULL;

    return value;
}

char peek(struct memory *stack){
    
    printf("\n  Peeking %c", stack -> stack[stack -> size-1]);
    return stack -> stack[stack -> size-1];
}

int pdaStateZero(char input[]){
    //INITIALIZE THE PDA
    //Keep track of position in the string
    int pos = 0;
    //Initialize Stack
    struct memory stack;
    stackInit(&stack);

    
    printf("\nState Zero");

    //First Passthrough (If i = j)
    if (pdaStateOne(input, stack, pos) == 1) return 1;

    //Second Passthrough (If j = k)
    return pdaStateFour(input, stack, pos);
}

int pdaStateOne(char input[], struct memory stack, int pos){
    printf("\nState One");
    
    if(pos < 265 && input[pos] != NULL){

        if(input[pos] == 'a') {

            push(&stack, 'x');

            return pdaStateOne(input, stack, ++pos);

        } 
        
        else if (input[pos] == 'b'){

            if(peek(&stack) != 'x') return 0;

            else {
                pop(&stack);
                return pdaStateTwo(input, stack, ++pos);
            }

        }

        else {
            return -1;
        }

    } else return 0;
}

int pdaStateTwo(char input[], struct memory stack, int pos){
    printf("\nState Two");

    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'b'){
            if(peek(&stack) != 'x') {
                return 0;
            } else {
                pop(&stack);
                return pdaStateTwo(input, stack, ++pos);
            }
        } else if (input[pos] == 'c') {
            return pdaStateThree(input, stack, ++pos);
        } else {
            return -1;
        }


    } else return 0;
}

//Because these are PDAs, the Automaton has to read the entire string, so even if the As and Bs are the same and we would already know by now
//It is important to read the rest of the input, because PDAs can't stop whenever it wants, it has to get to the final state.
int pdaStateThree(char input[], struct memory stack, int pos){
    printf("\nState Three");

    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'c'){
            return pdaStateThree(input, stack, ++pos);
        } else {
            return -1;
        }

    } else if(peek(&stack) == '$'){
        return pdaStateSeven();
    }
}

int pdaStateFour(char input[], struct memory stack, int pos){
    printf("\nState Four");

    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'a'){
            return pdaStateFour(input, stack, ++pos);
        } else if (input[pos] == 'b') {
            push(&stack, 'x');
            return pdaStateFive(input, stack, ++pos);
        } else {
            return -1;
        }
    } return 0;
}

int pdaStateFive(char input[], struct memory stack, int pos){
    printf("\nState Five");

    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'b'){
            push(&stack, 'x');
            return pdaStateFive(input, stack, ++pos);
        } else if (input[pos] == 'c') {
            if(peek(&stack) != 'x'){
                return 0;
            } else {
                pop(&stack);
                return pdaStateSix(input, stack, ++pos);
            }
        } else {
            return -1;
        }
    } return 0;
}

int pdaStateSix(char input[], struct memory stack, int pos){
    printf("\nState Six");

    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'c'){
            if(peek(&stack) != 'x'){
                return 0;
            } else {
                pop(&stack);
                return pdaStateSix(input, stack, ++pos);
            }
        } else return -1;
    } else if(peek(&stack) == '$'){
        return pdaStateSeven();
    }
}

int pdaStateSeven(){
    printf("\nState Seven");

    return 1;
}