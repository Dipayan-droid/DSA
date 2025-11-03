class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # Display the list
    def display(self):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        print("List elements:", end=" ")
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

    # Count nodes
    def count_nodes(self):
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.next
        print("Number of nodes:", count)
        return count

    # Add at beginning
    def add_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        print(f"Added {data} at the beginning.")

    # Add at end
    def add_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp
        print(f"Added {data} at the end.")

    # Add at position
    def add_at_position(self, data, pos):
        if pos <= 0:
            print("Position should be >= 1")
            return
        new_node = Node(data)
        if pos == 1:
            self.add_at_beginning(data)
            return
        temp = self.head
        for i in range(pos - 2):
            if temp is None:
                print("Position out of bounds")
                return
            temp = temp.next
        if temp is None:
            print("Position out of bounds")
            return
        new_node.next = temp.next
        if temp.next:
            temp.next.prev = new_node
        temp.next = new_node
        new_node.prev = temp
        print(f"Added {data} at position {pos}.")

    # Search element
    def search(self, key):
        temp = self.head
        pos = 1
        while temp:
            if temp.data == key:
                print(f"Element {key} found at position {pos}.")
                return
            temp = temp.next
            pos += 1
        print(f"Element {key} not found.")

    # Delete from beginning
    def delete_from_beginning(self):
        if not self.head:
            print("List is empty.")
            return
        removed = self.head.data
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        print(f"Deleted element {removed} from beginning.")

    # Delete from end
    def delete_from_end(self):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        if temp.next is None:
            removed = temp.data
            self.head = None
            print(f"Deleted element {removed} from end.")
            return
        while temp.next:
            temp = temp.next
        removed = temp.data
        temp.prev.next = None
        print(f"Deleted element {removed} from end.")

    # Delete from position
    def delete_from_position(self, pos):
        if not self.head:
            print("List is empty.")
            return
        if pos <= 0:
            print("Position should be >= 1")
            return
        if pos == 1:
            self.delete_from_beginning()
            return
        temp = self.head
        for i in range(pos - 1):
            if temp is None:
                print("Position out of bounds")
                return
            temp = temp.next
        if temp is None:
            print("Position out of bounds")
            return
        removed = temp.data
        if temp.next:
            temp.next.prev = temp.prev
        if temp.prev:
            temp.prev.next = temp.next
        print(f"Deleted element {removed} from position {pos}.")

def main():
    dll = DoublyLinkedList()
    while True:
        print("\nMenu:")
        print("1. Display")
        print("2. Add at Beginning")
        print("3. Add at End")
        print("4. Add at Position")
        print("5. Search Element")
        print("6. Count Nodes")
        print("7. Delete from Beginning")
        print("8. Delete from End")
        print("9. Delete from Position")
        print("10. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            dll.display()
        elif choice == 2:
            data = int(input("Enter data: "))
            dll.add_at_beginning(data)
        elif choice == 3:
            data = int(input("Enter data: "))
            dll.add_at_end(data)
        elif choice == 4:
            data = int(input("Enter data: "))
            pos = int(input("Enter position: "))
            dll.add_at_position(data, pos)
        elif choice == 5:
            key = int(input("Enter element to search: "))
            dll.search(key)
        elif choice == 6:
            dll.count_nodes()
        elif choice == 7:
            dll.delete_from_beginning()
        elif choice == 8:
            dll.delete_from_end()
        elif choice == 9:
            pos = int(input("Enter position to delete: "))
            dll.delete_from_position(pos)
        elif choice == 10:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
