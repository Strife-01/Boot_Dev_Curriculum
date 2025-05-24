def factorial(num):
    if num < 0:
        raise Exception("num cannot be negative")
    rez = 1
    for i in range(2, num + 1):
        rez *= i
    return rez

