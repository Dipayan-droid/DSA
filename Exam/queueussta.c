#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    int arr[MAX];
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Push an element to stack
void push(struct Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

// Pop an element from stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        // printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Queue using two stacks
struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

// Initialize queue
void initQueue(struct Queue* q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}

// Enqueue operation
void enqueue(struct Queue* q, int val) {
    push(&q->stack1, val);
    printf("Enqueued %d\n", val);
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            int val = pop(&q->stack1);
            push(&q->stack2, val);
        }
    }
    int val = pop(&q->stack2);
    if (val == -1)
        printf("Queue is empty\n");
    else
        printf("Dequeued %d\n", val);
    return val;
}

// Display queue elements from front to rear
void display(struct Queue* q) {
    if (isEmpty(&q->stack1) && isEmpty(&q->stack2)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");

    // Print elements of stack2 from top to bottom
    for (int i = q->stack2.top; i >= 0; i--) {
        printf("%d ", q->stack2.arr[i]);
    }
    // Print elements of stack1 from bottom to top
    for (int i = 0; i <= q->stack1.top; i++) {
        printf("%d ", q->stack1.arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    int choice, val;

    initQueue(&q);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
