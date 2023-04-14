#include<stdio.h>
#include<stdlib.h>
//#include<limits.h>
#include "stack.h"
#include "linkedlist.h"

void init(stack *s) {
    s->top = NULL;
}

//void pushOnStack(stack *s, int data) {
//    snode *nn = (snode *)malloc(sizeof(node));
//    if(!nn) return;
//
//    nn->data = data;
//    nn->next = NULL;
//
//    if(isEmpty(*s)) {
//        s->top = nn;
//        return;
//    }
//    nn->next = s->top;
//    s->top = nn;
//    return;
//}
//
//int pop(stack *s){
//    if(isEmpty(*s)) return INT_MIN;
//    snode *p = s->top;
//    int ele = s->top->data;
//    if(!p->next) {
//        s->top = NULL;
//        free(p);
//        return ele;
//    }
//    s->top = p->next;
//    free(p);
//    return ele;
//}
//
//int peek(stack s) {
//    if(isEmpty(s)) return INT_MIN;
//    return (s.top)->data;
//}
int isEmpty(stack s) {
    return s.top == NULL;
}

void push_stack(stack *s, List data){
    snode* nn = (snode*)malloc(sizeof(snode));
    nn -> data = data;
    nn -> next = NULL;

    if(isEmpty(*s)){
        s->top = nn;
        return;
    }

    nn -> next = s->top;
    s->top = nn;
    printf("\n");
}

List pop_stack(stack *s){
    if(isEmpty(*s)){
        return NULL;
    }
    snode* temp = s->top;
    List ele = temp->data;
    s->top = s->top->next;
    free(temp);
    return ele;
}

//void pushop(stackop *s, char ch) {
//    nodeop *nn = (nodeop *)malloc(sizeof(nodeop));
//    if(!nn) return;
//
//    nn->op = ch;
//    nn->next = NULL;
//
//    if(isEmptyOp(*s)) {
//        s->top = nn;
//        return;
//    }
//    nn->next = s->top;
//    s->top = nn;
//    return;
//}
//
//char popop(stackop *s) {
//    char ch = '?';
//    if(isEmptyOp(*s)) return ch;
//    snode *p = s->top;
//    ch = s->top->op;
//    if(!p->next) {
//        s->top = NULL;
//        free(p);
//        return ch;
//    }
//    s->top = p->next;
//    free(p);
//    return ch;
//}
//
//int isEmptyOp(stackop s) {
//    return s.top == NULL;
//}
//

//void intopost(stack *s,char exp[],char post[]) {
//    int i,j;
//    for(i=0,j=-1;exp[i]!='\0';i++){
//        if(exp[0]=='-'){
//            post[++j]=exp[0];
//            i++;
//            exp[0]='|';
//        }
//        printf("%c",exp[i]);
//        if(exp[i]>='0' && exp[i]<='9'){
//            post[++j]=exp[i];
//
//        }
//        else{
//            post[++j]='|';
//            if(exp[i]== '+' ||exp[i]== '-' ||exp[i]== '*' ||exp[i]== '/' ||exp[i]== '%' || exp[i]=='^')
//            {
//                while(s->top!=NULL && precedence(exp[i])<=precedence(s->top->data))
//                {
//                    post[++j]=pop(s);
//                }
//                pushOnStack(&s,exp[i]);
//
//            }
//        }
//    }
//    while(s->top!=NULL){
//        char x=pop(s);
//        post[++j]=x;
//    }
//    //  printf("\npostfix:%s",post);
//    printf("\n");
//    i=0;
//    // while(post[i]!='\0')
//    // {
//    // 	if(post[i]=='|'){
//    // 	i++;
//    // 	continue;}
//    //     printf("%c",post[i]);
//    //     i++;
//    // }
//
//}

//void scan(char post[],stack *s1) {
//    int i,k;
//    List *temp=NULL;
//    int len1,len2;
//    push(&temp,1);
//    List *head=NULL,*head2=NULL,*ptr,*result=NULL;
//    List *p=head;
//    List* q=head2;
//    int count=0;
//    stack *k1=s1;
//
//    push(&s1,INT_MIN);
//
//    for(i=0;post[i]!='\0';i++){
//
//        if(post[0]=='-'){
//            push(&s1,post[++i]-48);
//            s1->top->data=-s1->top->data;
//            i++;
//            post[0]='?';
//        }
//
//        if((post[i]>='0' && post[i]<='9')  || post[i]=='|') {
//            if(post[i]=='|')
//                push(&s1,INT_MIN);
//            else
//                push(&s1,post[i]-48);
//
////            printf("\npushed from post to stack %c",post[i]);
//
//        }
//
//
//        else if(post[i]== '+' ||post[i]== '-' ||post[i]== '*' || post[i]=='/' ||post[i]== '%'|| post[i]=='^' || post[i]=='>' ||post[i]=='<' ||post[i]=='=') {
//
////        	k1=s1;
////        	while(k1!=NULL)
////        	{
////
////        		printf("\ndata%d",k1->data);
////        		k1=k1->next;
////			}
//            k = pop(s1);
//            if (count(k) != 1)
//                k = popno(s1);
//            while (countdigit(k) == 1) {
//
//                head = insertdata(head, k);
//
//                k = popno(s1);
//            }
//            k = popno(s1);
//            if (countdigit(k) != 1)
//                k = popno(s1);
//            while (countdigit(k) == 1 && topno != NULL) {
//
//                head2 = insertdata(head2, k);
//                k = popno(s1);
//            }
//            s1 = pushno(s1, INT_MIN);
//        }