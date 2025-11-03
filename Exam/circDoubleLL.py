class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None

    # Count nodes
    def count_nodes(self):
        if not self.head:
            print("Number of nodes: 0")
            return 0
        count = 1
        temp = self.head.next
        while temp != self.head:
            count += 1
            temp = temp.next
        print("Number of nodes:", count)
        return count

    # Display list
    def display(self):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        print("List elements:", end=" ")
        while True:
            print(temp.data, end=" ")
            temp = temp.next
            if temp == self.head:
                break
        print()

    # Add at beginning
    def add_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
        else:
            tail = self.head.prev
            new_node.next = self.head
            new_node.prev = tail
            tail.next = new_node
            self.head.prev = new_node
            self.head = new_node
        print(f"Added {data} at beginning.")

    # Add at end
    def add_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
        else:
            tail = self.head.prev
            tail.next = new_node
            new_node.prev = tail
            new_node.next = self.head
            self.head.prev = new_node
        print(f"Added {data} at end.")

    # Add at position
    def add_at_position(self, data, pos):
        length = self.count_nodes()
        if pos < 1 or pos > length + 1:
            print("Invalid position.")
            return
        if pos == 1:
            self.add_at_beginning(data)
            return
        if pos == length + 1:
            self.add_at_end(data)
            return
        new_node = Node(data)
        temp = self.head
        for _ in range(pos - 2):
            temp = temp.next
        next_node = temp.next
        temp.next = new_node
        new_node.prev = temp
        new_node.next = next_node
        next_node.prev = new_node
        print(f"Added {data} at position {pos}.")

    # Search element
    def search(self, key):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        pos = 1
        while True:
            if temp.data == key:
                print(f"Element {key} found at position {pos}.")
                return
            temp = temp.next
            pos += 1
            if temp == self.head:
                break
        print(f"Element {key} not found.")

    # Delete from beginning
    def delete_from_beginning(self):
        if not self.head:
            print("List is empty.")
            return
        tail = self.head.prev
        removed = self.head.data
        if self.head.next == self.head:
            self.head = None
        else:
            self.head = self.head.next
            tail.next = self.head
            self.head.prev = tail
        print(f"Deleted element {removed} from beginning.")

    # Delete from end
    def delete_from_end(self):
        if not self.head:
            print("List is empty.")
            return
        tail = self.head.prev
        removed = tail.data
        if self.head.next == self.head:
            self.head = None
        else:
            new_tail = tail.prev
            new_tail.next = self.head
            self.head.prev = new_tail
        print(f"Deleted element {removed} from end.")

    # Delete from position
    def delete_from_position(self, pos):
        length = self.count_nodes()
        if pos < 1 or pos > length:
            print("Invalid position.")
            return
        if pos == 1:
            self.delete_from_beginning()
            return
        if pos == length:
            self.delete_from_end()
            return
        temp = self.head
        for _ in range(pos - 1):
            temp = temp.next
        removed = temp.data
        prev_node = temp.prev
        next_node = temp.next
        prev_node.next = next_node
        next_node.prev = prev_node
        print(f"Deleted element {removed} from position {pos}.")

def main():
    dcll = DoublyCircularLinkedList()
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
            dcll.display()
        elif choice == 2:
            data = int(input("Enter data to add at beginning: "))
            dcll.add_at_beginning(data)
        elif choice == 3:
            data = int(input("Enter data to add at end: "))
            dcll.add_at_end(data)
        elif choice == 4:
            data = int(input("Enter data to add: "))
            pos = int(input("Enter position: "))
            dcll.add_at_position(data, pos)
        elif choice == 5:
            key = int(input("Enter element to search: "))
            dcll.search(key)
        elif choice == 6:
            dcll.count_nodes()
        elif choice == 7:
            dcll.delete_from_beginning()
        elif choice == 8:
            dcll.delete_from_end()
        elif choice == 9:
            pos = int(input("Enter position to delete: "))
            dcll.delete_from_position(pos)
        elif choice == 10:
            print("Exiting program.")
            break
        else:
            print("Invalid choice, try again.")

if __name__ == "__main__":
    main()
