#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to left shift the list by k nodes
struct Node* leftShiftByK(struct Node* head, int k) {
    if (head == NULL || k == 0) return head;

    struct Node* current = head;
    int count = 1;

    // Traverse till kth node
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    // If k is greater than or equal to list length, no change
    if (current == NULL) return head;

    // kth node
    struct Node* kthNode = current;

    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // Connect last node to head
    current->next = head;

    // New head is next of kth node
    head = kthNode->next;

    // Break the list after kth node
    kthNode->next = NULL;

    return head;
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
    // Create a linked list: 1->2->3->4->5->NULL
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 3;

    printf("Original list:\n");
    printList(head);

    head = leftShiftByK(head, k);

    printf("List after left shifting by %d nodes:\n", k);
    printList(head);

    return 0;
}
