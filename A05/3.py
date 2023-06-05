class Node:
    def __init__ (self, value, before, next):
        self.value = value
        self.before = before
        self.next = next

class LinkedList:
    def __init__ (self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def insert_at_head (self, value):
        if self.head:
            node = Node(value, None, self.head)
            self.head.before = node
            self.head = node
        else:
            self.head = Node(value, None, None)
            self.tail = self.head
        self.size += 1

    def insert_at_tail (self, value):
        if self.tail:
            node = Node(value, self.tail, None)
            self.tail.next = node
            self.tail = node
        else:
            self.tail = Node(value, None, None)
            self.head = self.tail
        self.size += 1
    
    def get_size (self):
        return self.size
    
    def delete_by_value (self, value):
        cursor = self.head
        while cursor:
            if cursor.value == value:
                if self.get_size() == 1:
                    self.head = None
                    self.tail = None
                else:
                    if cursor.next and cursor.before:
                        cursor.next.before = cursor.before
                        cursor.before.next = cursor.next
                    elif not cursor.next:
                        cursor.before.next = None
                        self.tail = cursor.before
                    else:
                        cursor.next.before = None
                        self.head = cursor.next
                self.size -= 1
                del cursor
                break
            cursor = cursor.next

    def does_exist (self, value):
        cursor = self.head
        while cursor:
            if cursor.value == value:
                return True
            cursor = cursor.next
        return False

    def reverse (self):
        cursor = self.head
        while cursor:
            cursor.before, cursor.next = cursor.next, cursor.before
            cursor = cursor.before
        self.head, self.tail = self.tail, self.head

    def display (self):
        cursor = self.head
        while cursor:
            print(cursor.value, end = "->")
            cursor = cursor.next
        print("None")
        
l = LinkedList()

while True:
    items = list(map(lambda x: x.lower(), input().split()))

    if items:
        if items[0] in {"tinsert", "tinsrt"}: 
            l.insert_at_tail(items[1])
        elif items[0] == "hinsert":
            l.insert_at_head(items[1])
        elif items[0] == "reverse":
            l.reverse()
        elif items[0] in {"exists", "exist"}:
            print(l.does_exist(items[1]))
        elif items[0] == "size":
            print(l.get_size())
        elif items[0] == "print":
            l.display()
        elif items[0] == "vdelete":
            l.delete_by_value(items[1])
        elif items[0] == "exit":
            break