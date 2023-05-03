#include "node.h"

//typedef struct nodeop {
//    char op;
//    struct nodeop *next;
//}nodeop;

typedef struct snode{
    Number data;
    struct snode *up;
}snode;

typedef struct NumStack{
    snode* top ;
}NumStack;

typedef struct CharStack{
    char *arr;
    int top;
    int size;
}CharStack;

// NumStack operations for storing the numbers
void initNumStack(NumStack*);
void pushNumOnStack(NumStack*, Number);
Number popNumFromStack(NumStack*);
Number getTopNumFromStack(NumStack);
int sizeofNumStack(NumStack);
void displayN(NumStack s);

// NumStack operations for storing all characters
void initStackC(CharStack*, int);
void pushC(CharStack*, char);
void displayC(CharStack);
int isFullC(CharStack);
int isEmptyC(CharStack);
void insertIntoStackC(CharStack*, char*);
int popC(CharStack*);
char topC(CharStack);