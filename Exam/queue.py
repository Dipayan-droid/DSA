class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        self.items.append(item)
        print(f"Enqueued {item} into queue")

    def dequeue(self):
        if self.is_empty():
            print("Queue Underflow! Queue is empty.")
            return None
        val = self.items.pop(0)
        print(f"Dequeued {val} from queue")
        return val

    def display(self):
        if self.is_empty():
            print("Queue is empty")
        else:
            print("Queue elements:", self.items)


def queue_menu():
    queue = Queue()
    while True:
        print("\n--- Queue Menu ---")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display")
        print("4. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            val = int(input("Enter value to enqueue: "))
            queue.enqueue(val)
        elif choice == '2':
            queue.dequeue()
        elif choice == '3':
            queue.display()
        elif choice == '4':
            print("Exiting queue program")
            break
        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    queue_menu()
