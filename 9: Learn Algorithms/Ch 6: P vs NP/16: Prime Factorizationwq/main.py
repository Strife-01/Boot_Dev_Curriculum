import math


def prime_factors(n):
    factors = []
    f = 2
    while n > 1:
        while n % f == 0:
            factors.append(f)
            n //= f
        f += 1
    
    return factors

