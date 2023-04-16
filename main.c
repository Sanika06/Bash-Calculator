#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"linkedList.h"
#include "stack.h"
#define MAX_EXPR_SIZE 1000

int precedence(char operator)
{
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

char* infixToPostfix(char* infix)
{
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
    printf("%s", postfix);
    return postfix;
}

List evaluate(char opr, List a, List b)
{
    List result = NULL;
    reverse(&a);
    reverse(&b);

    switch(opr)
    {
        case '+': result = addList(a, b);
            break;
        case '-': result = subList(a, b);
            break;
        case '*': result = mulList(a, b);
            break;
        case '/': result = divList(a, b);
            break;
        case '%': result = remainder(a, b);
            break;
        case '^': result = powList(a, b);
            break;
        default : printf("Invalid expression\n");
    }
    return result;
}

void generateANumbersFromString(char *postfix)
{
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

int main()
{   printf("Enter e to exit\n\n");
    char input[100];

    while(1)
    {
        fgets(input, 100, stdin);

        if(input[0] == 'e')
            break;
        char* postfix = infixToPostfix(input);

        generateANumbersFromString(postfix);
    }
    return 0;
}
