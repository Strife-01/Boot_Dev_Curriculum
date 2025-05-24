class HashMap:
    def insert(self, key, value):
        self.resize()
        index = self.key_to_index(key)
        self.hashmap[index] = (key, value)

    def resize(self):
        if len(self.hashmap) == 0:
            self.hashmap.append(None)
        current_load = self.current_load()
        if current_load * 100 < 5:
            return
        extension = [None for i in range(10 * len(self.hashmap))]
        for i in range(len(self.hashmap)):
            extension[i] = self.hashmap[i]
        self.hashmap = extension

    def current_load(self):
        if len(self.hashmap) == 0:
            return 1

        load = 0

        for b in self.hashmap:
            if b is not None:
                load += 1
        
        return load / len(self.hashmap)

    # don't touch below this line

    def __init__(self, size):
        self.hashmap = [None for i in range(size)]

    def key_to_index(self, key):
        sum = 0
        for c in key:
            sum += ord(c)
        return sum % len(self.hashmap)

    def __repr__(self):
        final = ""
        for i, v in enumerate(self.hashmap):
            if v != None:
                final += f" - {str(v)}\n"
        return final

