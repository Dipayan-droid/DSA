#include <stdio.h>
#define MAX 10

void RestoreHeapUp(int *, int);
void RestoreHeapDown(int *, int, int);

int main() {
    int Heap[MAX + 1], n, i, j;

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &Heap[i]);
        RestoreHeapUp(Heap, i); // Heapify after each insert
    }

    // Heap Sort
    j = n;
    for (i = 1; i < j; i++) {
        int temp = Heap[1];
        Heap[1] = Heap[n];
        Heap[n] = temp;
        n = n - 1;
        RestoreHeapDown(Heap, 1, n);
    }

    printf("The sorted elements are: ");
    for (i = 1; i <= j; i++)
        printf("%4d", Heap[i]);
    printf("\n");

    return 0;
}

// Maintain the max-heap property going up
void RestoreHeapUp(int *Heap, int index) {
    int val = Heap[index];
    while ((index > 1) && (Heap[index / 2] < val)) {
        Heap[index] = Heap[index / 2];
        index /= 2;
    }
    Heap[index] = val;
}

// Maintain the max-heap property going down
void RestoreHeapDown(int *Heap, int index, int n) {
    int val = Heap[index];
    int j = index * 2;
    while (j <= n) {
        if ((j < n) && (Heap[j] < Heap[j + 1]))
            j++;
        if (val >= Heap[j])
            break;
        Heap[index] = Heap[j];
        index = j;
        j = j * 2;
    }
    Heap[index] = val;
}
