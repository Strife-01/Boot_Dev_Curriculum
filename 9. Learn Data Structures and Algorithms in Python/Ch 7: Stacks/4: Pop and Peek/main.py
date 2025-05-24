class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def size(self):
        return len(self.items)

    def peek(self):
        return None if len(self.items) == 0 else self.items[-1]

    def pop(self):
        return None if len(self.items) == 0 else self.items.pop()

