def find_longest_word(document, longest_word=""):
    document = document.strip()
    words = document.split(' ')
    if len(words) == 0:
        return longest_word
    if len(words) == 1 and words[0] == '':
        return longest_word
    if len(longest_word) < len(words[0]):
        return find_longest_word(' '.join(words[1:]), words[0])
    return find_longest_word(' '.join(words[1:]), longest_word)
