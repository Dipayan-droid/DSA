#include <stdio.h>
#include <stdlib.h>

struct DoubleStack {
    int size;
    int top1;   // Top of stack 1
    int top2;   // Top of stack 2
    int *arr;
};

void pushStack1(struct DoubleStack *ds, int val) {
    if (ds->top1 + 1 == ds->top2) {
        printf("Stack Overflow for Stack 1!\n");
        return;
    }
    ds->top1++;
    ds->arr[ds->top1] = val;
    printf("Pushed %d to Stack 1\n", val);
}

void pushStack2(struct DoubleStack *ds, int val) {
    if (ds->top2 - 1 == ds->top1) {
        printf("Stack Overflow for Stack 2!\n");
        return;
    }
    ds->top2--;
    ds->arr[ds->top2] = val;
    printf("Pushed %d to Stack 2\n", val);
}

int popStack1(struct DoubleStack *ds) {
    if (ds->top1 == -1) {
        printf("Stack 1 Underflow!\n");
        return -1;
    }
    int val = ds->arr[ds->top1];
    ds->top1--;
    printf("Popped %d from Stack 1\n", val);
    return val;
}

int popStack2(struct DoubleStack *ds) {
    if (ds->top2 == ds->size) {
        printf("Stack 2 Underflow!\n");
        return -1;
    }
    int val = ds->arr[ds->top2];
    ds->top2++;
    printf("Popped %d from Stack 2\n", val);
    return val;
}

void displayStack1(struct DoubleStack *ds) {
    if (ds->top1 == -1) {
        printf("Stack 1 is empty.\n");
        return;
    }
    printf("Stack 1 elements: ");
    for (int i = 0; i <= ds->top1; i++) {
        printf("%d ", ds->arr[i]);
    }
    printf("\n");
}

void displayStack2(struct DoubleStack *ds) {
    if (ds->top2 == ds->size) {
        printf("Stack 2 is empty.\n");
        return;
    }
    printf("Stack 2 elements: ");
    for (int i = ds->top2; i < ds->size; i++) {
        printf("%d ", ds->arr[i]);
    }
    printf("\n");
}

int main() {
    struct DoubleStack ds;
    printf("Enter size of double stack: ");
    scanf("%d", &ds.size);
    ds.arr = (int*) malloc(ds.size * sizeof(int));
    ds.top1 = -1;
    ds.top2 = ds.size; // Stack 2 starts from end

    int choice, val;

    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value for Stack 1: ");
                scanf("%d", &val);
                pushStack1(&ds, val);
                break;
            case 2:
                printf("Enter value for Stack 2: ");
                scanf("%d", &val);
                pushStack2(&ds, val);
                break;
            case 3:
                popStack1(&ds);
                break;
            case 4:
                popStack2(&ds);
                break;
            case 5:
                displayStack1(&ds);
                break;
            case 6:
                displayStack2(&ds);
                break;
            case 7:
                free(ds.arr);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
