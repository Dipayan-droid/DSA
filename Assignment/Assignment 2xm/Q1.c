#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isFull(struct stack* ptr) {
    return ptr->top == ptr->size - 1;
}

int isEmpty(struct stack* ptr) {
    return ptr->top == -1;
}

void push(struct stack* ptr, int val) {
    if (isFull(ptr))
        printf("Stack Overflow\n");
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack* ptr) {
    if (isEmpty(ptr))
        printf("Empty stack\n");
    else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped item: %d\n", val);
    }
}

int peek(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return ptr->arr[ptr->top];
    }
}

void display(struct stack* ptr) {
    if (isEmpty(ptr))
        printf("Stack Empty\n");
    else {
        printf("Stack elements are:\n");
        for (int i = ptr->top; i >= 0; i--)
            printf("%d ", ptr->arr[i]);
        printf("\n");
    }
}

int main() {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    

    s->top = -1;
    s->size = 80;
    s->arr = (int*)malloc(s->size * sizeof(int));
    

    // Sample operations
    push(s, 10);
    push(s, 20);
    push(s, 30);

    display(s);

    printf("Top element is %d\n", peek(s));

    pop(s);
    pop(s);

    display(s);

    
    return 0;
}
