//
////
//// Created by Dell on 3/3/2023.
////
//#include<stdio.h>
//#include"linkedlist.h"
//#include<stdlib.h>
//
//void initList(List *l) {
//    *l = NULL;
//}
//
//node* createNewNode(List *l, int data) {
//    node *nn = (node*)malloc(sizeof(node));
//    if(!nn) return NULL;
//
//    nn->data = data;
//    nn->next = NULL;
//    return nn;
//}
//
//int count(List l) {
//    int count = 0;
//    node *p = l;
//    while(p) {
//        p = p->next;
//        count += 1;
//    }
//    //printf("Count is: %d\n", count);
//    return count;
//}
//
//void append(List *l, int data) {
//    node *nn = createNewNode(l, data);
//    if(!nn) return;
//
//    if(!(*l)) {
//        *l = nn;
//        return;
//    }
//
//    node *p = *l;
//    while(p->next) {
//        p = p->next;
//    }
//    p->next = nn;
//    return;
//}
//
//void push(List *l, int data) {
//    node *nn = createNewNode(l, data);
//    if(!nn) return;
//    nn->next = *l;
//    *l = nn;
//    return;
//}
//void reverse(List *l) {
//    node *p = *l;
//    node *q = NULL;
//    node *temp = NULL;
//    while(p) {
//        temp = p->next;
//        p->next = q;
//        q = p;
//        p = temp;
//    }
//    *l = q;
//    return;
//}
//
//int unitDigit(int pdata, int qdata, int *carry, char opr) {
//    int value = 0;
//    switch(opr) {
//        case '+':
//            value = pdata + qdata + *carry;
//            break;
//        case '*':
//            value = pdata * qdata + *carry;
//    }
//    *carry = 0;
//    int unit = value;
//    if(value >= 10) {
//        unit %= 10;
//        *carry = value/10;
//    }
//    return unit;
//}
//
//List addList(List l1, List l2) {
////    List sum;
////    initList(&sum);
//    node *p = l1;
//    node *q = l2;
//
//    int carry = 0;
//    int unit = 0;
//
//    while(p && q) {
//        unit = unitDigit(p->data, q->data, &carry, '+');
//        p->data = unit;
//        p = p->next;
//        q = q->next;
//    }
//
//    while(q) {
//        unit = unitDigit(0, q->data, &carry, '+');
//        append(&p, unit);
//        q = q->next;
//    }
//
//    while(p) {
//        unit = unitDigit(p->data, 0, &carry, '+');
//        p->data = unit;
//        p = p->next;
//    }
//
//    if(carry>0) {
//        append(&p, carry);
//    }
//
//    return l1;
//}
//
//// Remove Zeros
//List subList(List l1, List l2) {
//    List diff;
//    initList(&diff);
//
//    node *p, *q;
//
//    int sign = 0;   //positive
//
//    if(count(l1) == count(l2)) {
//        reverse(&l1);
//        printf("\nReverse of l1 is: ");
//        display(l1);
//
//        reverse(&l2);
//        printf("\nReverse of l2 is: ");
//        display(l2);
//
//        p = l1;
//        q = l2;
//        while (p && q) {
//            if (p->data < q->data) {
//                reverse(&l2);
//                reverse(&l1);
//                sign = -1;
//                break;
//            }
//            else if(p->data > q->data) {
//                break;
//            }
//            else {
//                p = p->next;
//                q = q->next;
//            }
//        }
//    }
//    p = l1;
//    q = l2;
//
//    if(count(l1) < count(l2) || sign == -1) {
//        p = l2;
//        q = l1;
//        sign = -1;   //negative
//    }
//
//    int unit = 0;
//
//    while(p && q) {
//        node *p1 = p;
//        node *p2 = p->next;
//        if(p->data < q->data) {
//            p1->data = p->data + 10;
//            p2->data = p2->data - 1;
//        }
//        unit = p->data - q->data;
//        append(&diff, unit);
//
//        p = p->next;
//        q = q->next;
//    }
//
//    while(p) {
//        if(!p->next && sign == -1)
//            p->data = p->data *(-1);
//
//        unit = p->data;
//        append(&diff, unit);
//        p = p->next;
//    }
//
//    return diff;
//}
///*
// * 1 2 3
// *   4 5
// *   1
// * 3 2 1    l1  p
// * 5 4      l2  q
// * 5
// *
// * int count = 0;
// * while(q) {
// *      carry = 0;
// *      while(count>0) {
// *          append(&mul, 0);
// *      }
// *      while(p) {
// *          push(&mul, unitDigit(p->data, q->data, int *carry, '*'));
// *          p = p->next;
// *      }
// *      addList(
// *      q = q->next;
// */
//List mulList(List l1, List l2) {
//
//}
//
//void display(List l) {
//    node* p = l;
//    while(p) {
//        printf("%d -> ", p->data);
//        p = p->next;
//    }
//    printf("NULL\n");
//}