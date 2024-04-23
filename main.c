#include <stdio.h>
#include <string.h>
#include <time.h>

//FORMATTING (Colors)
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
//FORMATTING (Colors)


//DRIVER
int main(int argc, char const *argv[])
{

    char decision;
    char input[256] = { NULL };
    
    //Saves me writing these 10 times
    char dfa[] = "DFA {w | w  contains at least two 0's and at most one 1}";
    char pda[] = "PDA {a^i b^j c^k | i, j, k >= 0 and i = j or j = k}";

    //Choosing between FSMs or Test Cases
    printf("Pick one of the following: \n 1. %s \n 2. %s \n 3. Test Cases for both DFA and PDA\n", dfa, pda);
    scanf("%c", &decision);

    //If decision isn't 3, grab the input line
    if(decision != '3'){
        printf("\nInput String:\n");
        scanf("%s", &input);
    }

    
    int result = 0;
    if(decision == '1') {
        result = dfaQ0(input);
    } else if (decision == '2'){
        result = pdaStateZero(input);
    } else if (decision == '3'){
        testCases();
        return 0;
    }

    //Calculation of manual test

    if(result == 0){
        printf("\nUnacceptable Grammar");
    } else if (result == 1){
        printf("\nAcceptable Grammar");
    } else {
        printf("\nERROR INVALID CHARACTER FORMAT\n\n");
    }
    
    return 0;
}


//Delay For Automatic Test Cases
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void testCases(){
    //DFA Test Cases
    testCaseTemplate(1,"0","DFA", 0); //Fail
    testCaseTemplate(2,"01","DFA", 0); //Fail
    testCaseTemplate(3,"1","DFA", 0); //Fail
    testCaseTemplate(4,"001","DFA", 1); //Pass
    testCaseTemplate(5,"0010000001","DFA", 0); //Fail
    testCaseTemplate(6,"10000","DFA", 1); //Pass
    testCaseTemplate(7,"1001000000001","DFA", 0); //Fail
    testCaseTemplate(8,"111","DFA", 0); //Fail
    testCaseTemplate(9,"0000","DFA", 1); //Pass
    testCaseTemplate(10,"000000010000000","DFA", 1); //Pass

    //PDA Test Cases
    testCaseTemplate(11, "abc", "PDA", 1); //Pass
    testCaseTemplate(12, "abbb", "PDA", 0); //Fail
    testCaseTemplate(13, "aabbbc", "PDA", 0); //Fail
    testCaseTemplate(14, "aabcc", "PDA", 1); //Pass
    testCaseTemplate(15, "abbbccc", "PDA", 0); //Fail
    testCaseTemplate(16, "aaaaabccccc", "PDA", 1); //Pass
    testCaseTemplate(17, "aaaaabbbbbccccc", "PDA", 1); //Pass
    testCaseTemplate(18, "abbbbbc", "PDA", 1); //Pass
    testCaseTemplate(19, "aaaaabccccccc", "PDA", 0); //Fail
    testCaseTemplate(20, "ac", "PDA", -1); //Fail
}

//Test Case Generator
void testCaseTemplate(int test, char input[], char type[], int expected){
    //Description of Test
    printf("\n\nPerforming Test %i:\n", test);
    printf("Automaton: %s\n", type);
    printf("Input: %s\n", input);
    
    //Run FSM
    int result = 0;
    if(type[0] == 'D')  result = dfaQ0(input);
    else result = pdaStateZero(input);

    //Print Expected Output
    if(expected == 0){
        printf(ANSI_COLOR_RED "\nExpected: Unacceptable Grammar (Doesn't Meet Requirements)" ANSI_COLOR_RESET);
    } else if (expected == 1){
        printf(ANSI_COLOR_GREEN "\nExpected: Acceptable Grammar" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED "\nExpected: Unacceptable Grammar (Incorrect Format / Language)" ANSI_COLOR_RESET);
    }

    //Print Actual Output
    if(result == 0){
        printf(ANSI_COLOR_RED "\nActual: Unacceptable Grammar (Doesn't Meet Requirements)" ANSI_COLOR_RESET);
    } else if (result == 1){
        printf(ANSI_COLOR_GREEN "\nActual: Acceptable Grammar" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED "\nActual: Unacceptable Grammar (Incorrect Format / Language)"ANSI_COLOR_RESET);
    }

    //Chill for 2 Seconds (Makes Reading Easier)
    delay(2);
}

/*
* Start of DFA | Each State has a corresponding method, for example: State 0 is dfaQ0
*/
int dfaQ0(char input[]){
    int pos = 0;
    // printf("\n\nState Zero\n");
    if(input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ1(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaQ3(input, ++pos);
        }
        else return -1;
    }
    else return 0;
}

int dfaQ1(char input[], int pos){
    // printf("State One\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ2(input, ++ pos);
        } else if (input[pos] == '0'){
            return dfaQ4(input, ++pos);
        }
        else return -1;
    }
     else return 0;
}

int dfaQ2(char input[] , int pos){
    // printf("State Two\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ2(input, ++ pos);
        } else if (input[pos] == '0'){
            return dfaQ2(input, ++pos);
        }
        else return -1;
    }
    else return 0;
}

int dfaQ3(char input[], int pos){
    // printf("State Three\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ4(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaQ5(input, ++pos);
        }
        else return -1;
    }
     else return 0;
}

int dfaQ4(char input[], int pos){
    // printf("State Four\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ2(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaQ6(input, ++pos);
        }
        else return -1;
    }
     else return 0;
}


int dfaQ5(char input[], int pos){
    // printf("State Five\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ6(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaQ5(input, ++pos);
        }
    }
     else return 1;
}

int dfaQ6(char input[], int pos){
    // printf("State Six\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ2(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaQ6(input, ++pos);
        }
    }
     else return 1;
}
/*
* End of DFA
*/


/*
* Start of PDA
*/

/*
* STACK FUNCTIONS
*/ 


//Stack Struct (I called it memory because it will be annoying using the word "stack" 15 times in a single line)
struct memory{
    int size;
    char stack[256];
};


//Initialize stack
int stackInit(struct memory *stack){

    stack -> size = 0;
    stack -> stack[0] = '$';

    return 0;
}

//Push Value to Stack
int push(struct memory *stack, char value){
    stack->size++;
    stack->stack[stack->size] = value;

    return 0;
}

//Pop Value off the stack
char pop(struct memory *stack){
    if(stack -> size == -1) return ('f');
    char value = stack->stack[stack->size];
    stack-> stack[stack -> size] = NULL;
    stack -> size--;
    
    return value;
}

//Read stack
char peek(struct memory *stack){
    if(stack -> size == -1) return 'f';
    return stack -> stack[stack -> size];
}

/*
* STACK FUNCTIONS END
*/ 



/*
* PDA Methods Start | Each State is described by the method name, for example: q0 = pdaStateZero
*/
int pdaStateZero(char input[]){
    //INITIALIZE THE PDA
    int pos = 0;
    
    //Initialize Stack
    struct memory stack;
    stackInit(&stack);

    return pdaStateOne(input, stack, pos);
}

int pdaStateOne(char input[], struct memory stack, int pos){
    // printf("\nState One");

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
    // printf("\nState Two");
    // printf("\n%s", stack.stack);

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
    // printf("\nState Three");

    if(pos < 265 && input[pos] != NULL){    
        if(input[pos] == 'c'){
            return pdaStateThree(input, stack, ++pos);
        } else return -1;

    } else return pdaStateSix(input, stack, pos);
}

int pdaStateFour(char input[], struct memory stack, int pos){
    // printf("\nState Four");
    // printf("\n%s", stack.stack);

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
    // printf("\nState Five");

    if(pos < 265 && input[pos] != NULL){
        if(input[pos] == 'c'){
            if(peek(&stack) != 'x') return 0;
            pop(&stack);
            return pdaStateFive(input, stack, ++pos);
        } else return -1;
    } else return pdaStateSix(input, stack, pos);

}

int pdaStateSix(char input[], struct memory stack, int pos){
    // printf("\nState Six");

    if(peek(&stack) != '$') return 0;
    return 1;
}

/*
* End PDA Methods
*/