class Trie:
    def advanced_find_matches(self, document, variations):
        #return self.find_matches("".join([c if c not in variations else variations[c] for c in document]))
        matches = set()
        for i in range(len(document)):
            level = self.root
            for j in range(i, len(document)):
                ch = document[j]
                char_check = variations.get(ch, ch)
                if char_check not in level:
                    break
                level = level[char_check]
                if self.end_symbol in level:
                    matches.add(document[i : j + 1])
        return matches


    # don't touch below this line

    def find_matches(self, document):
        matches = set()
        for i in range(len(document)):
            level = self.root
            for j in range(i, len(document)):
                ch = document[j]
                if ch not in level:
                    break
                level = level[ch]
                if self.end_symbol in level:
                    matches.add(document[i : j + 1])
        return matches

    def add(self, word):
        current = self.root
        for letter in word:
            if letter not in current:
                current[letter] = {}
            current = current[letter]
        current[self.end_symbol] = True

    def __init__(self):
        self.root = {}
        self.end_symbol = "*"
