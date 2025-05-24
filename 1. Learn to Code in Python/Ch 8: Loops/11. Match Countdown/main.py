def countdown_to_start():
    for i in range(10, 0, -1):
        print(f"{i}...", end="")
        if i != 1:
            print()
        else:
            print("Fight!")


# Don't edit below this line


def test():
    print("Counting down to match start:")
    countdown_to_start()
    print("=====================================")


def main():
    test()


main()


