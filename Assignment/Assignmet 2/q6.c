#include <stdio.h>

#define SIZE 100

int s1[SIZE], s2[SIZE];
int top1 = -1, top2 = -1;

void push(int *stack, int *top, int value) {
    stack[++(*top)] = value;
}

int pop(int *stack, int *top) {
    return stack[(*top)--];
}

void enqueue(int value) {
    push(s1, &top1, value);
}

int dequeue() {
    if (top2 == -1) {
        while (top1 != -1)
            push(s2, &top2, pop(s1, &top1));
    }
    if (top2 == -1) return -1;
    return pop(s2, &top2);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("%d\n", dequeue()); // 1
    printf("%d\n", dequeue()); // 2
    return 0;
}
