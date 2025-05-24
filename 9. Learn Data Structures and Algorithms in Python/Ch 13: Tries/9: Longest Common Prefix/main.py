class Trie:
    def longest_common_prefix(self):
        current = self.root
        prefix = ""
        while True:
            current_children = [letter for letter in current.keys() if letter != self.end_symbol]

            if self.end_symbol in current:
                break
            if len(current_children) == 1:
                prefix += current_children[0]
                current = current[current_children[0]]
            else:
                break
        return prefix

    # don't touch below this line

    def __init__(self):
        self.root = {}
        self.end_symbol = "*"

    def add(self, word):
        current = self.root
        for letter in word:
            if letter not in current:
                current[letter] = {}
            current = current[letter]
        current[self.end_symbol] = True

