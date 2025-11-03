#include <stdio.h>
#include <stdlib.h>

// Define node structure for linked list stack
struct Node {
    int data;
    struct Node* next;
};

// Check if stack (linked list) is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Push operation: insert at the top of the stack
void push(struct Node** top_ref, int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Stack Overflow! Memory allocation failed\n");
        return;
    }
    new_node->data = val;
    new_node->next = *top_ref;
    *top_ref = new_node;
    printf("Pushed %d onto the stack\n", val);
}

// Pop operation: remove from top of the stack
int pop(struct Node** top_ref) {
    if (isEmpty(*top_ref)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    struct Node* temp = *top_ref;
    int popped = temp->data;
    *top_ref = temp->next;
    free(temp);
    return popped;
}

// Peek operation: get the top element without removing
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Display operation: print all elements from top to bottom
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements from top to bottom: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack_top = NULL;
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&stack_top, val);
                break;
            case 2:
                val = pop(&stack_top);
                if (val != -1) {
                    printf("Popped %d from the stack\n", val);
                }
                break;
            case 3:
                val = peek(stack_top);
                if (val != -1) {
                    printf("Top element is: %d\n", val);
                }
                break;
            case 4:
                display(stack_top);
                break;
            case 5:
                // Free all nodes before exit
                while (!isEmpty(stack_top)) {
                    pop(&stack_top);
                }
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
