#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to swap elements pairwise
void pairwiseSwap(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        // Swap data of current node and next node
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        // Move two nodes ahead
        current = current->next->next;
    }
}

// Utility function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    // Create linked list: 1->2->3->4->NULL
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    printf("Original list:\n");
    printList(head);

    // Swap elements pairwise
    pairwiseSwap(head);

    printf("List after pairwise swap:\n");
    printList(head);

    return 0;
}
