#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

// Check if the queue is full
int isFull(struct CircularQueue* q) {
    return ((q->rear + 1) % q->size) == q->front;
}

// Check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(struct CircularQueue* q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = val;
    printf("Enqueued %d\n", val);
}

// Dequeue operation
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) { // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    printf("Dequeued %d\n", val);
    return val;
}

// Display queue elements
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    int choice, val;

    printf("Enter size of circular queue: ");
    scanf("%d", &q.size);
    q.arr = (int*)malloc(q.size * sizeof(int));
    q.front = -1;
    q.rear = -1;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                free(q.arr);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
