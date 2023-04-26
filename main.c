#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "linkedList.h"
//#include "stack.h"
//#include "evaluate.h"

void evall(char arr[]) {
    int i, flag = 0;
    char c;
    List l1, l2;
    List result;
    initList(&l1);
    initList(&l2);
    initList(&result);
    for (i = 0; arr[i] != '\0'; i++) {
        if (flag == 0 && arr[i] >= '0' && arr[i] <= '9')
            push(&l1, arr[i] - 48);
        else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%') {
            c = arr[i];
//            printf("%c", c);
            flag = 1;
        }
        else {
            push(&l2, arr[i] - 48);
        }
    }
        switch (c) {
        case '+':
                result = addList(l1, l2);
                break;
        case '-':
                result = subList(l1, l2);
                break;
        case '*':
                result = mulList(l1, l2);
                break;
        case '/':
                result = divList(l1, l2);
                break;
        case '%':
                result = modList(l1, l2);
                break;
        }

    display(result);
}

int main() {
        List l1,l2;
        char arr[1000];
        gets(arr);
//        printf("%s",arr);
        evall(arr);
        return 0;
}