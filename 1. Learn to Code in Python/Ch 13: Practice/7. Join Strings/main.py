def join_strings(strings):
    new_string = ""
    if not len(strings): return new_string
    for i in range(len(strings) - 1):
        new_string += strings[i] + ','
    new_string += strings[-1]
    return new_string
