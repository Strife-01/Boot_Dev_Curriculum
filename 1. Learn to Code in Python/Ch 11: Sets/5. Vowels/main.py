def count_vowels(text):
    vowels = {'a', 'e', 'i', 'o', 'u'}
    our_vowels = set();
    nr_of_vowels = 0
    for c in text:
        if c.lower() in vowels:
            our_vowels.add(c)
            nr_of_vowels += 1
    return nr_of_vowels, our_vowels
