//
// Created by Dell on 4/20/2023.
//

#ifndef BINARY_CALCULATOR_EVALUATE_H
#define BINARY_CALCULATOR_EVALUATE_H

#include "linkedlist.h"
#include "stack.h"
#define MAX_EXPR_SIZE 1000

void initNumber(Number **N);
int precedence(char operator);
int isOperator(char ch);
char* generateNumber(Number **N, char *infix);
char* infixToPostfix(char* infix);
List evaluate(char opr, List a, List b);
void generateANumbersFromString(char *postfix);

void RemoveSpaces(char* source);
int pr(char elem);
void infix_to_postfix(char *infix, char *postfix);
void solve(int op1, int op2, char ch, Number **L);
int eval_postfix(char *postfix, Number **L) ;

#endif //BINARY_CALCULATOR_EVALUATE_H
