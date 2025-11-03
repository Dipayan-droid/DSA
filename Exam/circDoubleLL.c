#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to count nodes
int countNodes() {
    if (head == NULL) return 0;
    int count = 1;
    struct Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Add at beginning
void addAtBeginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    } else {
        struct Node* tail = head->prev;

        new_node->next = head;
        new_node->prev = tail;

        tail->next = new_node;
        head->prev = new_node;

        head = new_node;
    }
    printf("Added %d at beginning.\n", data);
}

// Add at end
void addAtEnd(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    } else {
        struct Node* tail = head->prev;

        tail->next = new_node;
        new_node->prev = tail;

        new_node->next = head;
        head->prev = new_node;
    }
    printf("Added %d at end.\n", data);
}

// Add at position
void addAtPosition(int data, int pos) {
    int length = countNodes();
    if (pos < 1 || pos > length + 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        addAtBeginning(data);
        return;
    }
    if (pos == length + 1) {
        addAtEnd(data);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node* temp = head;
    int i;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    struct Node* next_node = temp->next;

    temp->next = new_node;
    new_node->prev = temp;

    new_node->next = next_node;
    next_node->prev = new_node;

    printf("Added %d at position %d.\n", data, pos);
}

// Search element
void search(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element %d not found.\n", key);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* tail = head->prev;
    struct Node* temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        head = head->next;
        tail->next = head;
        head->prev = tail;
    }
    printf("Deleted element %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* tail = head->prev;
    if (head->next == head) {  // only one node
        printf("Deleted element %d from end.\n", tail->data);
        free(tail);
        head = NULL;
        return;
    }

    struct Node* prev_node = tail->prev;
    prev_node->next = head;
    head->prev = prev_node;
    printf("Deleted element %d from end.\n", tail->data);
    free(tail);
}

// Delete from position
void deleteFromPosition(int pos) {
    int length = countNodes();
    if (pos < 1 || pos > length) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    if (pos == length) {
        deleteFromEnd();
        return;
    }
    struct Node* temp = head;
    int i;
    for (i = 1; i < pos; i++) {
        temp = temp->next;
    }
    struct Node* prev_node = temp->prev;
    struct Node* next_node = temp->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    printf("Deleted element %d from position %d.\n", temp->data, pos);
    free(temp);
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Doubly Circular Linked List Menu ---\n");
        printf("1. Display\n");
        printf("2. Add at Beginning\n");
        printf("3. Add at End\n");
        printf("4. Add at Position\n");
        printf("5. Search\n");
        printf("6. Count Nodes\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete from Position\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                addAtBeginning(data);
                break;
            case 3:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                addAtEnd(data);
                break;
            case 4:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                addAtPosition(data, pos);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 6:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 10:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
