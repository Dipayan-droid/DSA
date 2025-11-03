class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)
        print(f"Pushed {item} onto stack")

    def pop(self):
        if self.is_empty():
            print("Stack Underflow! Stack is empty.")
            return None
        val = self.items.pop()
        print(f"Popped {val} from stack")
        return val

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        print(f"Top element is {self.items[-1]}")
        return self.items[-1]

    def display(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            print("Stack elements:", self.items)


def stack_menu():
    stack = Stack()
    while True:
        print("\n--- Stack Menu ---")
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Display")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            val = int(input("Enter value to push: "))
            stack.push(val)
        elif choice == '2':
            stack.pop()
        elif choice == '3':
            stack.peek()
        elif choice == '4':
            stack.display()
        elif choice == '5':
            print("Exiting stack program")
            break
        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    stack_menu()
