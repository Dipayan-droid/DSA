#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Display elements
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Count nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Add at beginning
void addAtBeginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
    printf("Added %d at the beginning.\n", data);
}

// Add at end
void addAtEnd(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        printf("Added %d as the first element.\n", data);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    printf("Added %d at the end.\n", data);
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

    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;

    printf("Added %d at position %d.\n", data, pos);
}

// Search element
void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
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
    struct Node* temp = head;
    if (temp->next == NULL) { // only one node
        head = NULL;
        printf("Deleted element %d from end.\n", temp->data);
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("Deleted element %d from end.\n", temp->data);
    free(temp);
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
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted element %d from position %d.\n", temp->data, pos);
    free(temp);
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Display\n");
        printf("2. Add at Beginning\n");
        printf("3. Add at End\n");
        printf("4. Add at Position\n");
        printf("5. Search Element\n");
        printf("6. Count Nodes\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete from Position\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
