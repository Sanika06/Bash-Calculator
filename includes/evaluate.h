//
// Created by Dell on 5/2/2023.
//

#ifndef BINARY_CALCULATOR_EVALUATE_H
#define BINARY_CALCULATOR_EVALUATE_H
#include "linkedlist.h"

int isNumber(char ch);
int precedence(char symbol);
Number applyOperand(Number,Number, char);
void infixEvaluation(char*);
int isCharacter(char);
#endif //BINARY_CALCULATOR_EVALUATE_H
