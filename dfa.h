int dfaStateOne(char input[], int pos){
    printf("\n\nState One\n");
    if(input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaStateTwo(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaStateFour(input, ++pos);
        }
        else return -1;
    }
    else return 0;
}

int dfaStateTwo(char input[], int pos){
    printf("State Two\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            //This would be state 3, but seeing as state 3 is always a fail state,
            //Might as well save the code and return 0
            return 0;
        } else if (input[pos] == '0'){
            return dfaStateFive(input, ++pos);
        }
        else return -1;
    }
     else return 0;
}

//
// NO STATE THREE
//

int dfaStateFour(char input[], int pos){
    printf("State Four\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaStateFive(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaStateSix(input, ++pos);
        }
        else return -1;
    }
     else return 0;
}

int dfaStateFive(char input[], int pos){
    printf("State Five\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            //This would be state 3, but seeing as state 3 is always a fail state,
            //Might as well save the code and return 0 (FAIL)
            return 0;
        } else if (input[pos] == '0'){
            return dfaStateSeven(input, ++pos);
        }
        else return -1;
    }
     else return 0;
}


int dfaStateSix(char input[], int pos){
    printf("State Six\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaStateSeven(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaStateSix(input, ++pos);
        }
    }
     else return 1;
}

int dfaStateSeven(char input[], int pos){
    printf("State Seven\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return 0;
        } else if (input[pos] == '0'){
            return dfaStateSeven(input, ++pos);
        }
    }
     else return 1;
}



