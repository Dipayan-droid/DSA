#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int *stack;
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    stack = (int *)malloc(SIZE * sizeof(int));

    push(10);
    push(20);
    push(30); 
    display();           // Output: 30 20 10
    printf("Popped: %d\n", pop());
    printf("Peek: %d\n", peek());
    display();

    free(stack);
    return 0;
}
