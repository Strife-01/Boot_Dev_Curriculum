def memo(f):
    cache = {}
    def inner(x):
        if x not in cache:
            cache[x] = f(x)
        return cache[x]
    return inner

@memo
def factorial_r(x):
    if x <= 1:
        return 1
    return x * factorial_r(x - 1)

