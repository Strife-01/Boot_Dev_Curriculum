from functools import reduce


def lines_with_sequence(char):
    def with_char(length):
        sequence = char * length
        def with_length(doc):
            occurences = 0
            for line in doc.split('\n'):
                if sequence in line:
                    occurences += 1
            return occurences
        return with_length
    return with_char

