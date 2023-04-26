#include "node.h"

//typedef struct nodeop {
//    char op;
//    struct nodeop *next;
//}nodeop;

typedef struct snode{
    List data;
    struct snode* next;
}snode;

typedef struct stack{
    snode* top;
}stack;


//typedef struct stackop {
//    nodeop *top;
//}stackop;

void init(stack *s);
//void pushOnStack(stack *s, int data);
//int pop(stack *s);
//int peek(stack s);
int isEmpty(stack s);
//void intopost(stack *s,char exp[],char post[]);
//void pushop(stackop *s, int data);
//char popop(stackop *s);
//int isEmptyOp(stackop s);
//void scan(char post[],stackop *s1);
void push_stack(stack *s, List data);
List pop_stack(stack *s);