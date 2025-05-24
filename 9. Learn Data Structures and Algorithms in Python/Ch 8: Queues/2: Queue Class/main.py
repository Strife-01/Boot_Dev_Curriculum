class Queue:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.insert(0, item)

    def pop(self):
        if len(self.items) == 0:
            return None
        item = self.items[-1]
        del self.items[-1]
        return item

    def peek(self):
        return None if len(self.items) == 0 else self.items[-1]

    def size(self):
        return len(self.items)

