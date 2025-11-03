#include <stdio.h>
#include <limits.h>
#define MAX 100

int idx = -1;
int pqVal[MAX];       // Data elements
int pqPriority[MAX];  // Associated priorities

int isEmpty() {
    return idx == -1;
}

int isFull() {
    return idx == MAX - 1;
}

// Enqueue: Insert an item with priority
void enqueue(int data, int priority) {
    if (!isFull()) {
        idx++;
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    } else {
        printf("Priority Queue Overflow!\n");
    }
}

// Peek: Return index of item with highest priority
int peek() {
    int maxPriority = INT_MIN, indexPos = -1;
    for (int i = 0; i <= idx; i++) {
        if (maxPriority < pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }
    return indexPos;
}

// Dequeue: Remove item with highest priority
void dequeue() {
    if (!isEmpty()) {
        int indexPos = peek();
        printf("Dequeued value: %d priority: %d\n", pqVal[indexPos], pqPriority[indexPos]);
        for (int i = indexPos; i < idx; i++) {
            pqVal[i] = pqVal[i+1];
            pqPriority[i] = pqPriority[i+1];
        }
        idx--;
    } else {
        printf("Priority Queue Underflow!\n");
    }
}

// Display priority queue contents
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue contents (value, priority):\n");
    for (int i = 0; i <= idx; i++) {
        printf("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}

int main() {
    enqueue(10, 2);
    enqueue(20, 4);
    enqueue(30, 3);
    enqueue(40, 5);
    enqueue(50, 1);
    printf("Priority Queue Before Dequeue:\n");
    display();

    dequeue();
    dequeue();
    printf("\nPriority Queue After Dequeue:\n");
    display();
    return 0;
}
