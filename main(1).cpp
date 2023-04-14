//
// Created by Dell on 4/3/2023.
//
//int main() {
//    List l1, l2, add, sub, mul, div, pow;
//
//    initList(&l1);
//    initList(&l2);
//    initList(&add);
//    initList(&sub);
//    initList(&mul);
//    initList(&div);
//    initList(&pow);
//
//    push(&l1, 5);
//    push(&l1, 9);
////    push(&l1, 6);
////    push(&l1, 5);
////    push(&l1, 3);
////    push(&l1, 2);
////    push(&l1, 1);
//
////    push(&l2, 4);
//    push(&l2, 5);
////    push(&l2, 1);
//    printf("Addition is: ");
//    add = addList(l1, l2);
//    display(add);
//
//    printf("Subtraction is: ");
//    sub = subList(l1, l2);
//    display(sub);
//
//    printf("Multiplication is: ");
//    mul = mulList(l1, l2);
//    display(mul);
////
////    printf("Division is: ");
////    div = divList(l1, l2);
////    display(div);
//
//    printf("Power is: ");
//    pow = powList(l1, l2);
//    display(pow);
//
//    return 0;
//}

//int main() {
//    char exp[1600],post[1600]={" "};
//    printf("enter infix expression:");
//    gets(exp);
//    stack *s=NULL;
//    stackop *s1=NULL;
//    intopost(s,exp,post);
//    scan(post,s1);
//    return 0;
//}

int main(){
    List l1, l2;
    char arr[1000];
    gets(arr);
//    puts(arr);
    eval(arr,l1,l2);
    return 0;
}

