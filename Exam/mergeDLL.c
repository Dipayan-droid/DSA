#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to print doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two sorted doubly linked lists
struct Node* mergeSortedDLL(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* mergedHead = NULL;

    // Initialize mergedHead to smaller first node
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    mergedHead->prev = NULL;

    struct Node* mergedTail = mergedHead;

    // Merge remaining nodes
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            mergedTail->next = head1;
            head1->prev = mergedTail;
            mergedTail = head1;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2->prev = mergedTail;
            mergedTail = head2;
            head2 = head2->next;
        }
    }

    // Attach remaining nodes if any
    if (head1 != NULL) {
        mergedTail->next = head1;
        head1->prev = mergedTail;
    } else if (head2 != NULL) {
        mergedTail->next = head2;
        head2->prev = mergedTail;
    }

    return mergedHead;
}

int main() {
    // Create first sorted doubly linked list: 1 <-> 3 <-> 5
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->prev = head1;
    head1->next->next = newNode(5);
    head1->next->next->prev = head1->next;

    // Create second sorted doubly linked list: 2 <-> 4 <-> 6
    struct Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->prev = head2;
    head2->next->next = newNode(6);
    head2->next->next->prev = head2->next;

    printf("List 1:\n");
    printList(head1);

    printf("List 2:\n");
    printList(head2);

    struct Node* mergedHead = mergeSortedDLL(head1, head2);
    printf("Merged Sorted List:\n");
    printList(mergedHead);

    return 0;
}
