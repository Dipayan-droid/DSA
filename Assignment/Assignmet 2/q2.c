#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int *queue;
int front = 0, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = value;
}

int dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    queue = (int *)malloc(SIZE * sizeof(int));

    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();            // Output: 1 2 3
    printf("Dequeued: %d\n", dequeue());
    display();

    free(queue);
    return 0;
}
