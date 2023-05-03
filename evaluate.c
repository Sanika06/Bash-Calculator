#include<stdio.h>
#include<stdlib.h>
#include"./includes/evaluate.h"
#include"./includes/stack.h"
int isNumber(char ch){
    int num = ch - '0';
    return (num <= 9 && num>=0);
}

int isOperator(char ch){
    return ((ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '(' || ch == ')' || ch == '%' || ch == '^'));
}

int isCharacter(char ch){
    return (ch >= 'a' && ch <= 'z' )|| (ch >= 'A' && ch <= 'Z');
}

int isAnythingOther(char ch){
    return (ch == '.' || ch == ',' || ch == ']' || ch == '['  );
}

int precedence(char symbol){
    if(symbol == '(')
        return 0;

    if(symbol == '^')
        return 3;

    if(symbol == '*' || symbol == '/' || symbol == '%')
        return 2;

    if(symbol == '+' || symbol == '-')
        return 1;

    return 0;
}


void freeList(List* numList){
    while(numList){
        List* freeNode = numList;
        *(numList) = (*numList)-> next;
        free(freeNode);
    }
}
void freeNumber(Number* numToFree){
    List temp = numToFree -> num;

    while(temp){
        List deleteNode = temp;
        temp = temp -> next;
        free(deleteNode);
    }
}


Number copyNumber(Number Num){
    Number num1;
    initNumber(&num1);

    while(Num.num){
        append(&num1.num, Num.num -> data);
        Num.num = Num.num -> next;
    }
    return num1;
}

int getAndReturnSignsOfNumber(Number a,Number b){       //returns the signs of numbers
    int sign = 0;
    if((a.sign == '+' && b.sign == '+')  ){
        sign = 1;       //both are positive, result is positive
    }
    else if((a.sign == '-' && b.sign == '+') || (a.sign == '+' && b.sign == '-'))
    {
        sign = 2;       //either or, result is negative
    }
    else{
        sign = -1;      //both nagative so result is positive
    }
    return sign;

}

Number applyOperand(Number a,Number b, char op){        //ACTUAL Operations are performed here
    Number result;
    initNumber(&result);
    int detectOp = getAndReturnSignsOfNumber(a, b);     //get signs
    int flag = 0;
    int dec  = 0;
    reverse(&a.num);
    reverse(&b.num);
    switch(op){
        case '+':
            if(detectOp == 1){      //both numbers are positive
                result.num = addList(a.num,b.num);
                result.sign = '+';
            }
            else if(detectOp == 2){     //if one is negative, then subtract
                result.num = subList(a.num,b.num);
            }
            else{                       //both are negative so add but result is negative
                result.num = addList(a.num,b.num);
                result.sign = '-';
            }
            break;

        case '-':
            if(a.sign == '-' && b.sign == '-'){     //if both are negative then second number becomes positive and then subtract 
                b.sign = '+';
                result.num = subList(a.num, b.num);

            }
            else if(detectOp == 1){         //if both are positive, then subtract
                result.num= subList(a.num, b.num);
            }
            else if(detectOp == 2){
                if( a.sign == '-'){     //if first number is negative then add the lists and result is negative
                    result.num= addList(a.num, b.num);
                    result.sign = '-';
                }
                else{               //if second number is negative then add the lists and result is positive
                    result.num= addList(a.num, b.num);
                    result.sign = '+';
                }
            }

            else{       //default
                result.num= addList(a.num, b.num);
                result.sign = '-';
            }
            break;


        case '*':
            flag = 1;
            result.num= mulList(a.num, b.num);  //multiply numbers
            if(detectOp == 2){      //if either is negative, the result is negative
                result.sign = '-';
            }
            else{       //if both are positive or both are negative, result is positive
                result.sign = '+';
            }
            break;

        case '/':
            flag = 1;
            result.num=  divList(a.num, b.num);     //divide numbers
            if(detectOp == 2){      //if either is negative, the result is negative
                result.sign = '-';
            }
            else{       //if both are positive or both are negative, result is positive
                result.sign = '+';
            }
            break;

        case '%': 
            result.num= modList(a.num, b.num);
            if(detectOp == 2){      //if either is negative, the result is negative
                result.sign = '-';
            }
            else{       //if both are positive or both are negative, result is positive
                result.sign = '+';
            }
            break;

        case '^' : result.num= powList(a.num, b.num);
            break;
    }

    return result;
}
void infixEvaluation(char *str){
    CharStack cStack;       //stack to store all operators
    NumStack nStack;        //stack to store the numbers for infix evaluation

    Number l1,l2,result;
    initNumber(&l1);
    initNumber(&l2);
    initNumber(&result);
    int count = 0 , countop = 0;

    for(int i = 0 ; str[i] != '\0' ; i++){      //count the no. of operators and operands
        if(isOperator(str[i]))
            countop++;
        count++;
    }

    int n = countop;
    initNumStack(&nStack);
    initStackC(&cStack,n);
    int flag = 0;
    int check = 0 ;

    for(int i = 0 ; i < count+1; i++){
        char ch = str[i];
        int num = ch - '0';
        if(i == 0 && (ch == '-' || ch == '+')){
            Number temp;
            initNumber(&temp);
            append(&temp.num,0);
            pushNumOnStack(&nStack, temp);
        }
        if(ch == ' ')
            continue;

        if(ch == '('){      //always push opening bracket on stack
            pushC(&cStack,'(');
        }

        else if(isNumber(ch)){      //-if numeric value, then add to list
            flag = 0;
            while(isNumber(ch)) {
                push(&l1.num,num);
                i++;
                ch = str[i];
                num = ch - '0';
                l1.count = l1.count + 1;
            }
            if(check == 2){     //check for negative value
                check = 0;
                if(l1.sign == '-' )
                    l1.sign = '+';
                else
                    l1.sign = '-';

            }
            else if(check == 3){
                check = 0;
                if(l1.sign == '-')
                    l1.sign = '-';
                else
                    l1.sign = '+';
            }
            else{
                check = 0;
            }
            l1.num = removeStartingZeros(l1.num);
            reverse(&l1.num);
            pushNumOnStack(&nStack,l1);
            initNumber(&l1);
            i--;
    }

        else if(ch == ')'){     //if closing bracket, pop all operators and evaluate simultaneously until opening bracket is found
            if(str[i-1] == '('){
                if(ch == '-' ){
                    check = 2;
                    continue;
                }
                else if( ch == '+'){
                    check = 3;
                    continue;
                }
            }
            while(!isEmptyC(cStack) && topC(cStack) != '(')
            {
                if(sizeofNumStack(nStack) < 2)
                {
                    printf("Invalid Operands");
                    exit(0);
                }

                Number val2 = popNumFromStack(&nStack);
                Number val1 = popNumFromStack(&nStack);

                //  printf("Signs %c %c",val1.sign,val2.sign);

                char op = topC(cStack);
                popC(&cStack);

                pushNumOnStack(&nStack, applyOperand(val1, val2, op));
            }

            if(!isEmptyC(cStack))
                popC(&cStack);
        }
        else if(isAnythingOther(ch)){
            printf("Invalid\n");
            exit(0);
        }
        else{       //if not brackets, then check for precedence, and perform operations accordingly
            if(l1.num){
                pushNumOnStack(&nStack, l1);
                initNumber(&l1);
            }

            else if(str[i-1] == '('){
                if(ch == '-' ){
                    check = 2;
                    continue;
                }
                else if( ch == '+'){
                    check = 3;
                    continue;
                }
            }
//if precedence of incoming operator is less than or equal to top of stack then pop the operator and evaluate
            while(topC(cStack) != ' ' && precedence(topC(cStack)) >= precedence(ch)){   
                if(sizeofNumStack(nStack) < 2)
                {
                    printf("Invalid Operands");
                    exit(0);
                }
                Number b = popNumFromStack(&nStack);
                Number a = popNumFromStack(&nStack);

                char ch = popC(&cStack);
                pushNumOnStack(&nStack, applyOperand(a, b, ch));
            }
            pushC(&cStack,ch);
        }
    }
    displayN(nStack);

}
