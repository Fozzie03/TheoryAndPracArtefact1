#include <stdio.h>
#include <string.h>


void FiniteAutomaton(char input[]){

}


int main(int argc, char const *argv[])
{
    char decision;
    char dfa[] = "DFA {w | w  contains at least two 0's and at most one 1}";
    char pda[] = "PDA {a^i b^j c^k | i, j, k >= 0 and i = j or j = k}";
    
    printf("Pick one of the following: \n 1. %s \n 2. %s \n", dfa, pda);

    scanf("%c", &decision);
    printf("You chose: ");

    (decision == '1') ? printf(dfa) : printf(pda);

    scanf("%s", )

    if(decision == '1') {
        print(dfa);
    }
    
    

    return 0;
}
