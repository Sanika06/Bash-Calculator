
//
// Created by Dell on 3/3/2023.
//
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include"linkedlist.h"
#include"stack.h"

void initList(List *l) {
    *l = NULL;
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
    //printf("Count is: %d\n", count);
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
 //   printf("\n%d appended",(*l)->data);
    return;
}
void push(List *l, int data) {
    node *nn = createNewNode(l, data);
    if(!nn) return;
    nn->next = *l;
    *l = nn;
    return;
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
    return;
}
List copyLinkedList(List l1, List l2) {
    node *p = l1;
    node *q = l2;
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
List removeLeadingZeros(List head) {
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

List subList(List l1, List l2)
{
    if (!(l1))
        return l2;

    if(!(l2))
        return l1;
//    reverse(&l1);
//    reverse(&l2);
    List result;
    initList(&result);

    int diff = 0, borrow = 0;
    node *p = l1;
    node *q = l2;

    if(!compareTwoLinkedlists(l1,l2))
    {
        p = l2;
        q = l1;
    }

    while(p && q)
    {
        diff = p -> data - q -> data - borrow;

        if(diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        append(&result, diff);

        p = p -> next;
        q = q -> next;

    }

    while(p)
    {
        diff = p -> data - borrow;
        if(diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        append(&result, diff);

        p = p -> next;
    }

    while(q)
    {
        diff = q -> data - borrow;
        if(diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        append(&result, diff);

        q = q -> next;
    }
    reverse(&result);
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
    product = removeLeadingZeros(product);
    return product;
}

List divList(List dividend, List divisor) {
    List orgdvs;
    initList(&orgdvs);
    orgdvs = copyLinkedList(divisor, orgdvs);
    List dvsCopy = orgdvs;
    reverse(&dividend);
    reverse(&divisor);
    node* p = dividend;
    List l1;
    initList(&l1);

    node *remainder;
    List quotient;
    initList(&quotient);
    initList(&remainder);

    if(isZero(divisor)) {
        append(&quotient, INT_MIN);
        return quotient;
    }
    if(compareTwoLinkedlists(dividend, divisor) == 2) {     //if both lists are same
        append(&quotient, 1);
        return quotient;
    }
    node *q = divisor;
    int flag = 0;

    while(p) {
        if(q->next) {
            append(&l1, p->data);
            p = p->next;
            flag = 1;
        }
        while(p && compareTwoLinkedlists(l1, divisor) == 0) {    //if first list is smaller than second
            append(&l1, p->data);
            if(flag == 1)   append(&quotient, 0);
            p = p->next;
        }
        int count = 0;

        while (compareTwoLinkedlists(l1, divisor) == 1 || compareTwoLinkedlists(l1, divisor) == 2) {      //while dividend is greater than or equal
            reverse(&l1);
            l1 = subList(l1, orgdvs);
            if(isZero(l1)) flag = 1;
            count++;
            divisor = removeLeadingZeros(divisor);
        }
        if(count >= 10) {
            append(&quotient, count%10);
            count = count/10;
        }
        append(&quotient, count);

        if(isZero(l1))  l1 = NULL;
    }
    quotient = removeLeadingZeros(quotient);
    return quotient;
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

//void eval(char arr[], List l1, List l2) {
//    int i;
//    char c;
////    puts(arr);
////    stack s;
//    List result;
//    initList(&result);
//    for(i=0;arr[i]!='\0';i++) {
////        printf("%c",arr[i]);
//        if(arr[i]>'0' && arr[i]<'9') {
//            push(&l1, (arr[i] - 48));
//            display(l1);
//        }
//        else if(arr[i]=='+'){
//            c=arr[i];
//            push(&l2,arr[++i]-48);
//            printf("i do %c",c);
//        display(l2);
//
//
//        }
//
//
//        switch(c) {
//            case '+':
//                printf("heyyyy");
//                result = addList(l1, l2);
//
//                display(result);
//                break;
//            case '-':
//                result = subList(l1, l2);
//                display(result);
//                break;
//            case '*':
//                result = mulList(l1, l2);
//                display(result);
//                break;
//            case '/':
//                result = divList(l1, l2);
//                display(result);
//                break;
//            case '^':
//                result = powList(l1, l2);
//                display(result);
//                break;
//        }
//    }
//}

void display(List l) {
    node* p = l;
    while(p) {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}