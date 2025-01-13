def get_num_guesses(length):
    return 26 ** length + get_num_guesses(length - 1) if length > 0 else 0

