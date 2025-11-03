#include <stdio.h>
#include <stdlib.h>

// Definition of node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create node
struct node* createNode(int data) {
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Create tree recursive input
struct node* createTree() {
    int val;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &val);
    if (val == -1) return NULL;

    struct node *root = createNode(val);
    printf("Enter left child of %d\n", val);
    root->left = createTree();
    printf("Enter right child of %d\n", val);
    root->right = createTree();
    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Count total nodes
int countNodes(struct node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Find height
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

// Search for data
struct node* search(struct node* root, int key) {
    if (!root) return NULL;
    if (root->data == key) return root;
    struct node* found = search(root->left, key);
    if (found) return found;
    return search(root->right, key);
}

// Main program
int main() {
    struct node* root = NULL;
    int choice, val;
    printf("Create the binary tree:\n");
    root = createTree();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Count Nodes\n");
        printf("5. Height\n");
        printf("6. Count Leaf Nodes\n");
        printf("7. Count Internal Nodes\n");
        printf("8. Search Data\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 2: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 3: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 4: printf("Number of nodes: %d\n", countNodes(root)); break;
            case 5: printf("Height of tree: %d\n", height(root)); break;
            case 6: printf("Number of leaf nodes: %d\n", countLeaf(root)); break;
            case 7: printf("Number of internal nodes: %d\n", countInternal(root)); break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("%d is present in the tree.\n", val);
                else
                    printf("%d not found.\n", val);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}
