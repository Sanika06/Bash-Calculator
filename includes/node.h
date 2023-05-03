//
// Created by Dell on 3/28/2023.
//

#ifndef BINARY_CALCULATOR_NODE_H
#define BINARY_CALCULATOR_NODE_H
typedef struct node {
    int data;
    struct node* next;
}node;
typedef node* List;

typedef struct Numbers {
    char sign;
    int count;
    List num;
}Number;
#endif //BINARY_CALCULATOR_NODE_H
