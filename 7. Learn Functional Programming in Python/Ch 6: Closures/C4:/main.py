from functools import reduce


def lineator(line_length):
    def lineate(document):
        words = document.split()

        def add_word_to_lines(lines, word):
            if len(lines) == 0:
                return [word]
            current_line = lines[-1]
            if len(current_line) + len(word) + 1 > line_length:
                lines.append(word)
            else:
                lines[-1] = f"{current_line} {word}"
            return lines

        return reduce(add_word_to_lines, words, [])

    return lineate

