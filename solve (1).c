#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "linkedlist.h"
#include "stack.h"
void initstack(stack *s)
{
    *s = NULL;
    return ;
}

int isFull(stack s)
{
    return 0;
}

int isEmpty(stack s)
{
    if(!s)
        return 1;
    return 0;
}

void pushOnStack(stack *s, node *l)
{
    stack nn = (stack)malloc(sizeof(snode));
    nn->c = l;
    if(!nn)
    {
        nn->next = NULL;
        return ;
    }
    if(!(*s))
    {
        *s = nn;
        (*s)->next = NULL;
        return;
    }
    nn->next = *s;
    *s = nn;
    return;
}

node *pop(stack *s)
{
    if(isEmpty(*s))
        return NULL;
    stack p = *s;
    node *temp = p->c;
    *s = p->next;
    free(p);
    return temp;
}

void pushop(stack *s, char c)
{
    snode *nn = (snode*)malloc(sizeof(snode));
    nn->ch = c;
    if(!(*s))
    {
        *s = nn;
        (*s)->next = NULL;
        return;
    }
    nn->next = *s;
    *s = nn;
    return;
}

char popop(stack *s)
{
    if(isEmpty(*s))
        return '\0';
    char c = (*s)->ch;
    (*s) = (*s)->next;
    return c;
}

int operators(char ch){
    if(ch == '+' || ch == '/' || ch == '-' || ch == '*')
    {
        return 1;
    }
    return 0;
}

int precedence(char c)
{
    if(c == '/' || c == '*')
        return 3;
    if(c == '+' || c == '-')
        return 2;
}

node *perform(node *l1, node *l2, char c)
{
    switch(c)
    {
        case '+':
            l1 = addList(l1,l2);
            break;

        case '*':
            l1 = mulList(l1,l2);
            break;
        case '-':
            l1 = subList(l1, l2);
        case '/':
            l1 = divList(l1, l2);
    }
    return l1;
}