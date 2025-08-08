#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q) {
    return (q->r == q->f);
}

int isFull(struct queue *q) {
    return (q->r == q->size - 1);
}

void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("The Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("The Queue is empty\n");
        return -1;
    } else {
        q->f++;
        return q->arr[q->f];
    }
}

void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = q->f + 1; i <= q->r; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int choice, val;

    do {
        printf("\n*** Queue Operations ***\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
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
                val = dequeue(&q);
                if (val != -1) {
                    printf("Dequeued element: %d\n", val);
                }
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);

    free(q.arr);
    return 0;
}
