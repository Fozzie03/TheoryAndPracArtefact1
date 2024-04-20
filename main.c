#include <stdio.h>
#include <string.h>
#include "dfa.h"
#include "pda.h"


int main(int argc, char const *argv[])
{
    char decision;
    char input[256] = { NULL };
    char dfa[] = "DFA {w | w  contains at least two 0's and at most one 1}";
    char pda[] = "PDA {a^i b^j c^k | i, j, k >= 0 and i = j or j = k}";
    
    printf("Pick one of the following: \n 1. %s \n 2. %s \n", dfa, pda);

    scanf("%c", &decision);
    printf("You chose: ");

    (decision == '1') ? printf(dfa) : printf(pda);

    printf("\nInput String:\n");
    scanf("%s", &input);
    int result = 0;
    if(decision == '1') {
        result = dfaQ0(input, 0);
    } else if (decision == '2'){
        result = pdaStateZero(input);
    }

    if(result == 0){
        printf("\nUnacceptable Grammar");
    } else if (result == 1){
        printf("\nAcceptable Grammar");
    } else {
        printf("\nError, Possible Character in Grammar that doesn't exist in this language");
    }
    
    

    return 0;
}
