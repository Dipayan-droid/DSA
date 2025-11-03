class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverse_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next  # store next node
        current.next = prev       # reverse the pointer
        prev = current            # move prev pointer forward
        current = next_node       # move current pointer forward
    return prev  # new head of the reversed list

def print_list(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")

# Example usage
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

print("Original list:")
print_list(head)

head = reverse_list(head)

print("Reversed list:")
print_list(head)
