class Trie:
    def search_level(self, cur, cur_prefix, words):
        if self.end_symbol in cur:
            words.append(cur_prefix)
        keys = cur.keys()
        for key in sorted(keys):
            if key != self.end_symbol:
                self.search_level(cur[key], cur_prefix + key, words)
        return words

    def words_with_prefix(self, prefix):
        list_of_prefixed_words = []
        start_key = self.root
        for letter in prefix:
            if letter not in start_key:
                return list_of_prefixed_words
            start_key = start_key[letter]
        return self.search_level(start_key, prefix, list_of_prefixed_words)

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

