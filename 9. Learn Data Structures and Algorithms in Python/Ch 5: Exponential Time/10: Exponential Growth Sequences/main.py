def exponential_growth(n, factor, days):
    return [n] + [n * factor ** d for d in range(1, days + 1)]
