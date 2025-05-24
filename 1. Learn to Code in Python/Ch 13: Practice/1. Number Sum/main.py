def number_sum(n):
    if n < 0:
        raise Exception("n is negative")
    return sum([i for i in range(n + 1)])

