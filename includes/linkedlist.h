//
// Created by Dell on 3/3/2023.
//
#include "node.h"
#ifndef BINARY_CALCULATOR_LINKEDLIST_H
#define BINARY_CALCULATOR_LINKEDLIST_H
//typedef node* List;
void initList(List *l);
node* createNewNode(List *l, int data);
void append(List *l, int data);
void push(List *l, int data);
void reverse(List *l);
int compareTwoLinkedlists(List l1, List l2);
int isZero(List l1);
List removeStartingZeros(List head);
void display(List l);
int unitDigit(int pdata, int qdata, int *carry, char opr);
List addList(List l1, List l2);
List subList(List l1, List l2);
List mulList(List l1, List l2);
List divList(List dividend, List divisor);
List remainder(List dividend, List divisor);
List powList(List l1, List pow);
void eval(char arr[], List l1, List l2);

#endif //BINARY_CALCULATOR_LINKEDLIST_H