
//
// Created by Dell on 3/3/2023.
//
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include"./includes/linkedlist.h"
#include"./includes/stack.h"

void initList(List *l) {
    *l = NULL;
}
void initNumber(Number *n) {
    n->sign = '+';
    initList(&n->num);
    n->count = 0;
}
node* createNewNode(List *l, int data) {
    node *nn = (node*)malloc(sizeof(node));
    if(!nn) return NULL;

    nn->data = data;
    nn->next = NULL;
    return nn;
}
int count(List l) {
    int count = 0;
    node *p = l;
    while(p) {
        p = p->next;
        count += 1;
    }
    return count;
}
void append(List *l, int data) {
    node *nn = createNewNode(l, data);
    if(!nn) return;

    if(!(*l)) {
        *l = nn;
        return;
    }

    node *p = *l;
    while(p->next) {
        p = p->next;
    }
    p->next = nn;
}
void push(List *l, int data) {
    node *nn = createNewNode(l, data);
    if(!nn) return;
    nn->next = *l;
    *l = nn;
}
void reverse(List *l) {
    node *p = *l;
    node *q = NULL;
    node *temp = NULL;
    while(p) {
        temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    *l = q;
}
List copyLinkedList(List l1, List l2) {
    node *p = l1;
    while(p) {
        append(&l2, p->data);
        p = p->next;
    }
    return l2;
}
void makeListsEqual(List *l1, List *l2) {
    while(count(*l1)>count(*l2)) {
        push(l2, 0);
    }
    while(count(*l2) > count(*l1)) {
        push(l1, 0);
    }
    return;
}
List removeStartingZeros(List head) {
    if(isZero(head)) {
        List newHead;
        initList(&newHead);
        append(&newHead, 0);
        return newHead;
    }
    while (head != NULL && head->data == 0) {
        node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;

}
int unitDigit(int pdata, int qdata, int *carry, char opr) {
    int value = 0;
    switch(opr) {
        case '+':
            value = pdata + qdata + *carry;
            break;
        case '*':
            value = pdata * qdata + *carry;
    }
    *carry = 0;
    int unit = value;
        unit %= 10;
        *carry = value/10;
    return unit;
}
int isZero(List l1) {
    node *p = l1;
    while(p) {
        if(p->data != 0) return 0;
        p = p->next;
    }
    return 1;
}
int compareTwoLinkedlists(List l1, List l2) {
    makeListsEqual(&l1, &l2);
    node* p = l1;
    node* q = l2;

    while(p) {
        if(p -> data > q -> data)
            return 1;       //if first list is greater
        else if(p -> data < q -> data)
            return 0;       //if second list is greater
        else
            p = p -> next;
            q = q -> next;
    }
    return 2;               //if both lists are equal
}
List addList(List l1, List l2){
    List sum;
    initList(&sum);
    node *p = l1;
    node *q = l2;

    int carry = 0;
    int unit = 0;

    while(p && q) {
        unit = unitDigit(p ->data, q ->data, &carry, '+');
        append(&sum, unit);
        p = p->next;
        q = q->next;
    }

    while(q) {
        unit = unitDigit(0, q ->data, &carry, '+');
        append(&sum, unit);
        q = q->next;
    }

    while(p) {
        unit = unitDigit(p ->data, 0, &carry, '+');
        append(&sum, unit);

        p = p->next;
    }

    if(carry>0) {
        append(&sum, carry);
    }
    reverse(&sum);
    return sum;
}

List subList(List l1, List l2) {
    if (!(l1))
        return l2;

    if(!(l2))
        return l1;
    List result;
    initList(&result);
    int diff = 0, borrow = 0, sign = 0; //sign = 0 is for positive
    node *p = l1;
    node *q = l2;
    reverse(&l1);
    reverse(&l2);

    if(!compareTwoLinkedlists(l1,l2)){
        p = l2;
        q = l1;
        sign = 1;
    }
    reverse(&l1);
    reverse(&l2);
    while(p && q){
        diff = p -> data - q -> data - borrow;

        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }

        append(&result, diff);

        p = p -> next;
        q = q -> next;

    }

    while(p){
        diff = p -> data - borrow;
        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        append(&result, diff);

        p = p -> next;
    }

    while(q){
//        flag = 1;
        diff = q -> data - borrow;
        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        append(&result, diff);

        q = q -> next;
    }
    reverse(&result);
    result = removeStartingZeros(result);
//    if(sign == 1) {
//        result->data = -result->data;
//    }
    return result;
}

List mulList(List l1, List l2) {
    List product, otherProduct;
    initList(&product);
    int rows = 0;
    int unit = 0;
    int carry = 0;

    List q = l2;

    while(q) {
        node *p = l1;
        carry = 0;
        initList(&otherProduct);

        while(p) {
            unit = unitDigit(p->data, q->data, &carry, '*');
            append(&otherProduct, unit);
            p = p->next;
        }

        for(int i= 0; i< rows; i++) {
            push(&otherProduct, 0);
        }

        if(carry) {
            append(&otherProduct, carry);
        }

        q = q->next;

        product = addList(product, otherProduct);
        reverse(&product);
        rows++;
    }
    reverse(&product);
    product = removeStartingZeros(product);
    return product;
}

//725279754/5 zero is not appending
List divList(List dividend, List divisor) {
    List quotient;
    initList(&quotient);
    if(isZero(divisor)) {
        append(&quotient, INT_MIN);
        return quotient;
    }

    List orgdvs;
    initList(&orgdvs);
    orgdvs = copyLinkedList(divisor, orgdvs);

    reverse(&dividend);
    reverse(&divisor);

    node* p = dividend;

    List l1;
    initList(&l1);

    node *remainder;

    initList(&remainder);

    int cmpResult = compareTwoLinkedlists(dividend, divisor);
    if(cmpResult == 2) {     //if both lists are same
        append(&quotient, 1);
        return quotient;
    }
    else if(cmpResult == 0) {
        append(&quotient, 0);
        return quotient;
    }

    node *q = divisor;
    int flag = 0, hasZero = 0;

    divisor = removeStartingZeros(divisor);

    while(p) {
        if(q->next) {
            append(&l1, p->data);
            p = p->next;
            flag = 1;
        }

        while(p && compareTwoLinkedlists(l1, divisor) == 0) {    //if first list is smaller than second
            append(&l1, p->data);
            if (p->data == 0) hasZero = 1;
            else hasZero = 0;
            if(flag || hasZero)   append(&quotient, 0);
            p = p->next;
        }
        int count = 0;
//        if(isZero(l1)) flag = 1;
        if(!isZero(l1)) {
            while (compareTwoLinkedlists(l1, divisor) == 1 || compareTwoLinkedlists(l1, divisor) == 2) {      //while dividend is greater than or equal
                reverse(&l1);
                l1 = subList(l1, orgdvs);
                count++;
            }
            if(count >= 10) {
                append(&quotient, count%10);
                count = count/10;
            }
            append(&quotient, count);

            if(isZero(l1))  l1 = NULL;
        }
        else {
            if(!hasZero)
                append(&quotient, 0);
            l1 = NULL;
        }
    }
    quotient = removeStartingZeros(quotient);
    return quotient;
}

List modList(List dividend, List divisor) {
    List remainder;
    if(isZero(divisor)) {
        append(&remainder, INT_MIN);
        return remainder;
    }
    List quotient, QD, dvsCopy, dvdCopy;
    initList(&quotient);
    initList(&remainder);
    initList(&QD);
    initList(&dvsCopy);
    initList(&dvdCopy);
    dvsCopy = copyLinkedList(divisor, dvsCopy);
    dvdCopy = copyLinkedList(dividend, dvdCopy);

    displayList(dvsCopy);
    quotient = divList(dividend, divisor);

    reverse(&quotient);

    QD = mulList(quotient, dvsCopy);

    reverse(&QD);

    remainder = subList(dvdCopy, QD);

    return remainder;
}

List powList(List l1, List pow) {
    List p = l1;
    List one;
    initList(&one);
    append(&one, 1);
    if(isZero(pow)) return one;
    pow = subList(pow, one);
    while(!isZero(pow)) {
        l1 = mulList(l1, p);
        reverse(&l1);
        pow = subList(pow, one);
    }
    reverse(&l1);
    return l1;
}

void displayNum(Number head){
    if(!head.num)
        return ;
    Number temp = head;
    if(head.num && !head.num -> next && head.num -> data == 0){  // if Answer is 0 then always set it as positive because 0 is never negative
        temp.sign = '+';
    }

    printf("= ");
    if(temp.sign == '-')
        printf(" %c",temp.sign);

    displayList(temp.num);
    printf("\n");
}

void displayList(List l) {
    node* p = l;
    while(p) {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}