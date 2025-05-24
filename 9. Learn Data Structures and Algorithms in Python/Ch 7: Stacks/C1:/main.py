from stack import Stack


class DebounceStack(Stack):
    def push(self, item):
        if self.peek() != item:
            self.items.append(item)
