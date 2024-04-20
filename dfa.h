int dfaQ0(char input[], int pos){
    printf("\n\nState One\n");
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
    printf("State Two\n");
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
    printf("State Two\n");
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
    printf("State Four\n");
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
    printf("State Five\n");
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
    printf("State Six\n");
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
    printf("State Seven\n");
    if(pos < 256 && input[pos] != NULL){
        if(input[pos] == '1'){
            return dfaQ2(input, ++pos);
        } else if (input[pos] == '0'){
            return dfaQ6(input, ++pos);
        }
    }
     else return 1;
}



