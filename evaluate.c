//
// Created by Dell on 4/20/2023.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "evaluate.h"

void initNumber(Number **N) {
    (*N) = (Number *) malloc(sizeof(Number));
    (*N)->sign = '+';
    (*N)->count = 0;
    (*N)->numbers = NULL;
}

int precedence(char operator){
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

char* generateNumbers(Number **N, char *infix) {
    char *operators = NULL, *str = NULL;
    int k = -1, index = 0, flag = 0;
    for(int i = 0; infix[i] !='\0'; i++) {
        if(isOperator(infix[i])) {
            str[++k] = index;
            str[++k] = infix[i];
            flag = 1;
            index++;
        }
        if(isalnum(infix[i])) {
            append(&(N[index])->numbers, infix[i]);
            flag = 0;
        }
    }
    if(flag == 0) {
        str[++k] = index;
    }
    return str;
}

char* infixToPostfix(char* infix){
    Number *N;
    exit(0);
    initNumber(&N);
    infix = generateNumbers(&N, infix);
    int i, j;
    unsigned long long len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    char stack[MAX_EXPR_SIZE];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }

        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }

        else if (isOperator(infix[i])) {
            postfix[j++] = ' ';
            while (top > -1
                   && precedence(stack[top])
                      >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }


    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("Postfix is:");
    printf("%s", postfix);
    return postfix;
}

List evaluate(char opr, List a, List b) {
    List result = NULL;
    reverse(&a);
    reverse(&b);

    switch(opr){
        case '+': result = addList(a, b);
            break;
        case '-': result = subList(a, b);
            break;
        case '*': result = mulList(a, b);
            break;
        case '/': result = divList(a, b);
            break;
        case '%': result = modList(a, b);
            break;
        case '^': result = powList(a, b);
            break;
        default : printf("Invalid expression\n");
    }
    return result;
}

void generateANumbersFromString(char *postfix) {
    unsigned long long len = strlen(postfix);

    stack st;
    init(&st);

    List num = NULL;

    for(int i = 0; i< len; i++)
    {
        if(isalnum(postfix[i])){
            append(&num, postfix[i] - '0');

        }
        else if(postfix[i] == ' ' || !isalnum(postfix[i]))
        {

            if(num)
                push_stack(&st, num);
            num = NULL;

        }
        if(isOperator(postfix[i]) && !isEmpty(st))
        {
            List b = pop_stack(&st);
            List a = pop_stack(&st);

            List res = evaluate(postfix[i],a,b);

            push_stack(&st, res);
        }

    }

    List result = pop_stack(&st);
    printf("= ");
    display(result);
    printf("\n");
}





//
//
//

#include <ctype.h>
#include <stdio.h>
//#include "./LinkedList.h"
//#include "./Operations.h"

char s[250];
int top = -1;

void RemoveSpaces(char* source) {
    char* i = source;
    char* j = source;
    while(*j != 0) {
        *i = *j++;
        if(*i != ' ')
            i++;
    }
    *i = 0;
}

void pushStack(char elem) {
    s[++top] = elem;
}

char popStack() {
    return (s[top--]);
}

int pr(char elem) {
    switch (elem) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    char ch, elem;
    int i = 0, k = 0;
//    printf("HI");
//    RemoveSpaces(infix);
    pushStack('#');

    while ((ch = infix[i++]) != '\n') {
        if (ch == '(')
            pushStack(ch);
        else if (isalnum(ch)) {
            postfix[k++] = ch;
            printf("%s", postfix);
        }
        else if (ch == ')') {
            while (s[top] != '(')
                postfix[k++] = popStack();
            elem = popStack();
        } else {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = popStack();
            pushStack(ch);
        }
    }

    while (s[top] != '#')
        postfix[k++] = popStack();

    postfix[k] = 0;
//    display(postfix);
    printf("%s", postfix);
}



//void solve(int op1, int op2, char ch, Number **L){
//    switch(ch) {
//        case '+' :
//            pushStack(addList(L, op1, op2, L[op1]->sign));
//            break;
//        case '-' :
//            if (L[op1]->count > L[op2]->count ) {
//                pushStack(subList(L, op1, op2, L[op1]->sign));
//
//            }
//            else if (L[op1]->count < L[op2]->count ) {
//                pushStack(subList(L, op2, op1, '-'));
//
//            } else{
//                if(isGreater(L[op1], L[op2] )){
//                    pushStack(subList(L, op1, op2, L[op1]->sign));
//                } else{
//                    pushStack(subList(L, op2, op1, '-'));
//                }
//            }
//
//            break;
//        case '*' :
//            if (L[op1]->sign == L[op2]->sign)
//                pushStack(mulList(L, op1, op2,'+'));
//            else
//                pushStack(mulList(L, op1, op2, '-'));
//            break;
//        case '/' :
//            if ( ( (L[op1]->count == L[op2]->count) && isGreater(L[op2], L[op1])) || L[op1]->count < L[op2]->count){
//
//                L[op1]->count = 1;
//                L[op1]->numbers->data = 0;
//                L[op1]->numbers->next = NULL;
//                pushStack(op1);
//                break;
//            }
//            if (L[op1]->sign == L[op2]->sign)
//                pushStack(divList(L, op1, op2,'+'));
//            else
//                pushStack(divList(L, op1, op2, '-'));
//            break;
//        case '%':
//            if (L[op1]->sign == L[op2]->sign)
//                pushStack(modList(L, op1, op2,'+'));
//            else
//                pushStack(modList(L, op1, op2, '-'));
//            break;
//            //  case '^':
//            //    if (L[op1]->sign == L[op2]->sign)
//            //      pushStack(expoLists(L, op1, op2,'+'));
//            //    else
//            //      pushStack(expoLists(L, op1, op2, '-'));
//            //    break;
//    }
//
//
//}

//int eval_postfix(char *postfix, Number **L) {
//    char ch;
//    int i = 0, op1, op2;
//    while((ch = postfix[i++]) != 0) {
//        if(isdigit(ch))
//            pushStack(ch-'0');
//        else {
//            op2 = popStack();
//            op1 = popStack();
//
//            if((ch == '+') && (L[op1]->sign == L[op2]->sign )){
//                solve(op1, op2, '+', L);
//            } else if((ch == '+') && (L[op1]->sign != L[op2]->sign) ){
//                if (L[op1]->sign == '-')
//                    solve(op2, op1, '-', L);
//                else
//                    solve(op1, op2, '-', L);
//
//            } else if((ch == '-') && (L[op1]->sign !=  L[op2]->sign )){
//                solve(op1, op2, '+', L);
//            } else {
//                solve(op1, op2, ch, L);
//            }
//
//        }
//    }
//
//    reverse(&L[s[top]]->numbers);
//    return s[top];
//}

