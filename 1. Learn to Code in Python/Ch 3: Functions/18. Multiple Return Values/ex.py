def become_warrior(full_name, power):
    return f"{full_name} the worrior", power + 1


# Don't edit below this line


def main():
    test("Frodo Baggins", 5)
    test("Bilbo Baggins", 10)
    test("Gandalf The Grey", 9000)


def test(input1, input2):
    print(type(become_warrior(input1, input2)).__name__)
    result1, result2 = become_warrior(input1, input2)
    print(result1, "has a power level of:", result2)


main()


