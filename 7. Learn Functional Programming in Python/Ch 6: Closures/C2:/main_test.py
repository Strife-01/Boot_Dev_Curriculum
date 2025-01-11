from main import *


run_cases = [
    (("cap",), ["bussin", "salty"], ("cap", "bussin", "salty")),
    (("fam", "bae"), ["bestie", "tea"], ("fam", "bae", "bestie", "tea")),
    (("slay",), ["cringe"], ("slay", "cringe")),
]

submit_cases = run_cases + [
    ((), ["AF"], ("AF",)),
    (
        ("lowkey", "drip", "goat"),
        ["gucci", "shook", "boujee"],
        ("lowkey", "drip", "goat", "gucci", "shook", "boujee"),
    ),
]


def test(initial_words, words_to_add, expected_output):
    print("---------------------------------")
    print(f"Initial words: {initial_words}")
    print(f"Words to add: {words_to_add}")
    print(f"Expecting: {expected_output}")
    add_word = user_words(initial_words)
    result = initial_words
    for word in words_to_add:
        result = add_word(word)
    print(f"   Actual: {result}")
    if result != expected_output:
        print("Fail")
        return False
    print("Pass")
    return True


def main():
    passed = 0
    failed = 0
    for test_case in test_cases:
        correct = test(*test_case)
        if correct:
            passed += 1
        else:
            failed += 1
    if failed == 0:
        print("============= PASS ==============")
    else:
        print("============= FAIL ==============")
    print(f"{passed} passed, {failed} failed")


test_cases = submit_cases
if "__RUN__" in globals():
    test_cases = run_cases

main()

