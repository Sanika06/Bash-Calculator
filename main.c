#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "./includes/evaluate.h"

#define MAX 2048

void displayInformation(){
    printf("\nBC SANIKA KULKARNI - 142203011");
    printf("\nCopyright 2023 , Free Software Foundation under GNU");
    printf("\nThis is a free and open source software with ABSOLUTELY NO WARRANTY");
    printf("\nOperations Supported - (+  -  /  * %%)\n");
}

int main(){
    displayInformation();

    char str[MAX] = "";

    while(1){
        fgets(str,MAX,stdin);   //Get input STring

        unsigned long int len = strlen(str);    //store length of String

        if(len > 0 && str[len-1] == '\n'){      //handling end of string
            str[len-1] = '\0';
        }

        if(strcmp(str,"quit")== 0|| strcmp(str,"exit") == 0)    //exitting condition
            break;

        else if(strcmp(str,"clear") ==  0){     //clear screen if specified
            system("clear");
            displayInformation();
        }
        else{
            for(int i = 0 ; str[i] != '\0' ; i++){  //characters i.e. alphabets not allowed
                if(isCharacter(str[i]))
                {
                    printf("Invalid Expression\n");
                    exit(0);
                }
            }
        }
        infixEvaluation(str);   //evaluate expression

    }
    return 0;
}