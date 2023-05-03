#include<stdio.h>
#include<stdlib.h>
#include "./includes/linkedlist.h"
#include "./includes/stack.h"

void initNumStack(NumStack* s){
    s -> top = NULL;
}
int isEmptyN(NumStack s){
    return s.top == NULL;
}

void displayN(NumStack s){
    if(isEmptyN(s))
        return ;

    snode* temp = s.top;
    displayNum(temp->data);
    printf("\n");
}

Number getTopNumFromStack(NumStack s){
    Number newnode ;
    newnode.num = (List)malloc(sizeof(node));
    newnode.num -> data = -1;
    newnode.num -> next = NULL;
    if(!s.top)
        return newnode;
    return s.top -> data;
}


void pushNumOnStack(NumStack* s, Number data){

    snode* newnode = (snode*)malloc(sizeof(snode));
    newnode -> data = data;
    newnode -> up = NULL;

    if(isEmptyN(*s))
    {
        s -> top = newnode;
    }
    else
    {
        newnode -> up = s -> top;
        s -> top = newnode;
    }
    return ;
}

Number popNumFromStack(NumStack *s){
    if(isEmptyN(*s)){
        Number result ;
        initNumber(&result);
        return result;
    }
    snode* deleteNode = s -> top;
    Number actualList = deleteNode -> data;

    // free(deleteNode);
    // displayList(actualList);
    s -> top = s -> top -> up;

    return actualList;
}
// Node* top(NumStack);

int sizeofNumStack(NumStack s){
    if(isEmptyN(s))
        return 0;
    int ct = 0;
    snode* temp = s.top;
    while(temp){
        ct++;
        temp = temp -> up;
    }
    return ct;
}

void initStackC(CharStack* s, int size){
    s -> arr = (char*)malloc(sizeof(char)*size);
    s -> top = -1;
    s -> size = size;
    return ;
}

int isFullC(CharStack s){
    return s.top >=  s.size - 1;
}

void pushC(CharStack *s, char data){

    if(isFullC(*s)){
        return;
    }
    s -> top++;
    s -> arr[s -> top] = data;
    return ;
}

void displayC(CharStack s){

    if(s.top == -1 )
        return ;
    printf("\n");
    for(int i = s.size ; i >= 0 ; i--){
        printf("%c ",s.arr[i]);
    }

}
int isEmptyC(CharStack s){
    return s.top == -1;
}
void insertIntoStackC(CharStack* s, char* data)
{

    for(int i = 0 ; i < data[i] != '\0'; i++){
        if(i >= s -> size)
            return ;

        pushC(s,data[i]);
    }
    return ;
}
int popC(CharStack *s){
    if(isEmptyC(*s))
        return 0;

    int element = s -> arr[s->top];
    s -> top--;
    return element;
}


char topC(CharStack s){
    if(isEmptyC(s)){
        char c = ' ';
        return c;
    }
    return s.arr[s.top];
}