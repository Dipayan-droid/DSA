#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top1 = -1, top2 = SIZE;

void push1(int val) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top1] = val;
}

void push2(int val) {
    if (top2 - 1 == top1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[--top2] = val;
}

int pop1() {
    if (top1 == -1)
        return -1;
    return stack[top1--];
}

int pop2() {
    if (top2 == SIZE)
        return -1;
    return stack[top2++];
}

int main() {
    push1(10);
    push2(20);
    push1(30);
    push2(40);

    printf("%d\n", pop1()); // 30
    printf("%d\n", pop2()); // 40
    return 0;
}
