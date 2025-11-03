class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
class SingleLinkedList:
    def __init__(self):
        self.head = None
    def createNode(self,data):
        return Node(data)
    def insertatfirst(self,data):
        newNode = self.createNode(data)
        newNode.next = self.head
        self.head = newNode
    def insertatlast(self, data):
        newNode = self.createNode(data)
        if not  self.head:
            self.head = newNode
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode
    def insertatany(self, pos, data):
        temp = self.head
        for i in range(pos - 1):
            temp = temp.next
        newNode = self.createNode(data)
        newNode.next = temp.next
        temp.next = newNode
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, "->", end="")
            temp = temp.next
        print("NULL")
    def delatbeg(self):
        temp = self.head
        self.head = self.head.next
        del temp
    def delatlast(self):
        if self.head.next is None:
            del self.head
            self.head = None
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        del temp.next
        temp.next = None
    def delAny(self, pos):
        temp = self.head
        for i in range(pos - 1):
            temp = temp.next
        nodeToDelete = temp.next
        temp.next = nodeToDelete.next
        del nodeToDelete
sll = SingleLinkedList()

while True:
    print("\nMenu:")
    print("1. Insert at First")
    print("2. Insert at Last")
    print("3. Insert at Any Position")
    print("4. Display List")
    print("5. Delete at Beginning")
    print("6. Delete at End")
    print("7. Delete at Any Position")
    print("8. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        data = int(input("Enter data: "))
        sll.insertatfirst(data)
    elif choice == 2:
        data = int(input("Enter data: "))
        sll.insertatlast(data)
    elif choice == 3:
        data = int(input("Enter data: "))
        pos = int(input("Enter position (0-based): "))
        sll.insertatany(pos,data)
    elif choice == 4:
        sll.display()
    elif choice == 5:
        sll.delatbeg()
    elif choice == 6:
        sll.delatlast()
    elif choice == 7:
        pos = int(input("Enter position to delete : "))
        sll.delaAny(pos)
    elif choice == 8:
        break
    else:
        print("Wrong Choice")