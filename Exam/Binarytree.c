#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* createNode(int data) {
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Insert a node (for BST style)
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Inorder Traversal
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Preorder Traversal
void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Postorder Traversal
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Count nodes
int countNodes(struct node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Height of tree
int height(struct node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

// Count leaf nodes
int countLeaf(struct node* root) {
    if (!root) return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Count internal nodes
int countInternal(struct node* root) {
    if (!root || (!root->left && !root->right))
        return 0;
    return 1 + countInternal(root->left) + countInternal(root->right);
}

// Search for a data value
struct node* search(struct node* root, int key) {
    if (!root) return NULL;
    if (root->data == key) return root;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Count Nodes\n");
        printf("6. Height of Tree\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Count Internal Nodes\n");
        printf("9. Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Total number of nodes: %d\n", countNodes(root));
                break;
            case 6:
                printf("Height of tree: %d\n", height(root));
                break;
            case 7:
                printf("Number of leaf nodes: %d\n", countLeaf(root));
                break;
            case 8:
                printf("Number of internal nodes: %d\n", countInternal(root));
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("%d is present in the tree.\n", val);
                else
                    printf("Element not found.\n");
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}
