#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create a new node
struct node* createNode(int data) {
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Insert a node (BST property)
struct node* insert(struct node* root, int data) {
    if (!root)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Infix (inorder)
void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Prefix (preorder)
void preorder(struct node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postfix (postorder)
void postorder(struct node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
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

// Find minimum value
int findMin(struct node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

// Find maximum value
int findMax(struct node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
}

// Count NULL pointers
int countNullPointers(struct node* root) {
    if (!root) return 1;
    return countNullPointers(root->left) + countNullPointers(root->right);
}

// Balance factor of a node (absolute difference of heights)
int balanceFactor(struct node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh) ? lh - rh : rh - lh;
}

// Check if complete binary tree
int isComplete(struct node* root, int index, int node_count) {
    if (!root) return 1;
    if (index >= node_count) return 0;
    return isComplete(root->left, 2*index+1, node_count) &&
           isComplete(root->right, 2*index+2, node_count);
}

// Deletion in BST
struct node* deleteNode(struct node* root, int key) {
    if (!root) return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Found node
        if (!root->left) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        int minVal = findMin(root->right);
        root->data = minVal;
        root->right = deleteNode(root->right, minVal);
    }
    return root;
}

// Main program
int main() {
    struct node* root = NULL;
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Infix (Inorder)\n");
        printf("3. Prefix (Preorder)\n");
        printf("4. Postfix (Postorder)\n");
        printf("5. Count Nodes\n");
        printf("6. Height of Tree\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Count Internal Nodes\n");
        printf("9. Search\n");
        printf("10. Complete Binary Tree Check\n");
        printf("11. Delete Node\n");
        printf("12. Balance Factor (at root)\n");
        printf("13. Find Minimum\n");
        printf("14. Find Maximum\n");
        printf("15. Count NULL Pointers\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Node count: %d\n", countNodes(root));
                break;
            case 6:
                printf("Tree height: %d\n", height(root));
                break;
            case 7:
                printf("Leaf node count: %d\n", countLeaf(root));
                break;
            case 8:
                printf("Internal node count: %d\n", countInternal(root));
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
            case 10: {
                int nodes = countNodes(root);
                if (isComplete(root, 0, nodes))
                    printf("Tree is complete\n");
                else
                    printf("Tree is NOT complete\n");
                break;}
            case 11:
                printf("Enter node to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Node deleted if existed.\n");
                break;
            case 12:
                printf("Balance factor (root): %d\n", balanceFactor(root));
                break;
            case 13:
                printf("Minimum value: %d\n", findMin(root));
                break;
            case 14:
                printf("Maximum value: %d\n", findMax(root));
                break;
            case 15:
                printf("Number of NULL pointers: %d\n", countNullPointers(root));
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
