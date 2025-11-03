class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    # Insert a node
    def insert(self, root, data):
        if root is None:
            return Node(data)
        if data < root.data:
            root.left = self.insert(root.left, data)
        elif data > root.data:
            root.right = self.insert(root.right, data)
        return root

    # Infix (inorder) traversal
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.data, end=' ')
            self.inorder(root.right)

    # Prefix (preorder)
    def preorder(self, root):
        if root:
            print(root.data, end=' ')
            self.preorder(root.left)
            self.preorder(root.right)

    # Postfix (postorder)
    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.data, end=' ')

    # Count nodes
    def countNodes(self, root):
        if root is None:
            return 0
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    # Height
    def height(self, root):
        if root is None:
            return 0
        left_height = self.height(root.left)
        right_height = self.height(root.right)
        return 1 + max(left_height, right_height)

    # Count leaf nodes
    def countLeaf(self, root):
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        return self.countLeaf(root.left) + self.countLeaf(root.right)

    # Count internal nodes
    def countInternal(self, root):
        if root is None or (root.left is None and root.right is None):
            return 0
        return 1 + self.countInternal(root.left) + self.countInternal(root.right)

    # Search a node
    def search(self, root, key):
        if root is None or root.data == key:
            return root
        if key < root.data:
            return self.search(root.left, key)
        return self.search(root.right, key)

    # Find minimum value
    def findMin(self, root):
        current = root
        while current.left:
            current = current.left
        return current.data

    # Find maximum value
    def findMax(self, root):
        current = root
        while current.right:
            current = current.right
        return current.data

    # Count NULL pointers (possible children spots that are empty)
    def countNullPointers(self, root):
        if root is None:
            return 1
        return self.countNullPointers(root.left) + self.countNullPointers(root.right)

    # Check if complete binary tree helper
    def isCompleteUtil(self, root, index, number_nodes):
        if root is None:
            return True
        if index >= number_nodes:
            return False
        return (self.isCompleteUtil(root.left, 2 * index + 1, number_nodes) and
                self.isCompleteUtil(root.right, 2 * index + 2, number_nodes))

    def isComplete(self, root):
        node_count = self.countNodes(root)
        return self.isCompleteUtil(root, 0, node_count)

    # Find node height
    def getBalanceFactor(self, node):
        if not node:
            return 0
        return self.height(node.left) - self.height(node.right)

    # Delete a node
    def delete(self, root, key):
        if root is None:
            return root
        if key < root.data:
            root.left = self.delete(root.left, key)
        elif key > root.data:
            root.right = self.delete(root.right, key)
        else:
            # node with one or no child
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp

            # node with two children
            temp_val = self.findMin(root.right)
            root.data = temp_val
            root.right = self.delete(root.right, temp_val)
        return root

# Example usage
if __name__ == "__main__":
    bst = BST()
    bst.root = None
    while True:
        print("\nMenu:")
        print("1. Insert")
        print("2. Inorder traversal")
        print("3. Preorder traversal")
        print("4. Postorder traversal")
        print("5. Count nodes")
        print("6. Height")
        print("7. Count leaf nodes")
        print("8. Count internal nodes")
        print("9. Search")
        print("10. Check if complete binary tree")
        print("11. Delete node")
        print("12. Get balance factor of root")
        print("13. Find min value")
        print("14. Find max value")
        print("15. Count null pointers")
        print("0. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            val = int(input("Enter value to insert: "))
            bst.root = bst.insert(bst.root, val)
        elif choice == 2:
            print("Inorder traversal: ", end="")
            bst.inorder(bst.root)
            print()
        elif choice == 3:
            print("Preorder traversal: ", end="")
            bst.preorder(bst.root)
            print()
        elif choice == 4:
            print("Postorder traversal: ", end="")
            bst.postorder(bst.root)
            print()
        elif choice == 5:
            print("Total nodes: ", bst.countNodes(bst.root))
        elif choice == 6:
            print("Height: ", bst.height(bst.root))
        elif choice == 7:
            print("Leaf nodes: ", bst.countLeaf(bst.root))
        elif choice == 8:
            print("Internal nodes: ", bst.countInternal(bst.root))
        elif choice == 9:
            k = int(input("Enter value to search: "))
            result = bst.search(bst.root, k)
            if result:
                print(f"{k} found in the tree.")
            else:
                print(f"{k} not found in the tree.")
        elif choice == 10:
            print("Complete Binary Tree?" , "Yes" if bst.isComplete(bst.root) else "No")
        elif choice == 11:
            val = int(input("Enter node value to delete: "))
            bst.root = bst.delete(bst.root, val)
            print(f"Node {val} deleted.")
        elif choice == 12:
            print("Balance factor at root:", bst.getBalanceFactor(bst.root))
        elif choice == 13:
            if bst.root:
                print("Minimum value:", bst.findMin(bst.root))
            else:
                print("Tree is empty")
        elif choice == 14:
            if bst.root:
                print("Maximum value:", bst.findMax(bst.root))
            else:
                print("Tree is empty")
        elif choice == 15:
            print("Number of NULL pointers:", bst.countNullPointers(bst.root))
        elif choice == 0:
            print("Exiting...")
            break
        else:
            print("Invalid choice")
