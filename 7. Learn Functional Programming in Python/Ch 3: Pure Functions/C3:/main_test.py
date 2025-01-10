import main as main_

run_cases = [
    (
        "Key parts of functional programming are higher-order functions and lambda expressions.",
        {},
        ["functional", "higher-order", "lambda"],
        {
            "Key parts of functional programming are higher-order functions and lambda expressions.": [
                "functional",
                "higher-order",
                "lambda",
            ]
        },
    ),
    (
        "Results are deterministic by using referential transparency and the absence of side-effects.",
        {},
        ["deterministic", "side-effects", "referential transparency"],
        {
            "Results are deterministic by using referential transparency and the absence of side-effects.": [
                "deterministic",
                "side-effects",
                "referential transparency",
            ]
        },
    ),
    (
        "Storing the results of deterministic functions uses memoization to help optimize functional code",
        {},
        ["functional", "deterministic", "memoization"],
        {
            "Storing the results of deterministic functions uses memoization to help optimize functional code": [
                "functional",
                "deterministic",
                "memoization",
            ]
        },
    ),
    (
        "Notably, functional programming emphasizes immutable data.",
        {
            "Notably, functional programming emphasizes immutable data.": [
                "test_keyword"
            ]
        },
        ["test_keyword"],
        {
            "Notably, functional programming emphasizes immutable data.": [
                "test_keyword"
            ]
        },
    ),
]

submit_cases = run_cases + [
    (
        "The immutable state in functional programming ensures referential transparency.",
        {},
        ["functional", "immutable", "referential transparency"],
        {
            "The immutable state in functional programming ensures referential transparency.": [
                "functional",
                "immutable",
                "referential transparency",
            ]
        },
    ),
    (
        "Functional programming often uses higher-order functions to handle side-effects declaratively.",
        {},
        ["declarative", "higher-order", "side-effects"],
        {
            "Functional programming often uses higher-order functions to handle side-effects declaratively.": [
                "declarative",
                "higher-order",
                "side-effects",
            ]
        },
    ),
    (
        "A concise method for implementing higher-order functions is through lambda functions.",
        {},
        ["higher-order", "lambda"],
        {
            "A concise method for implementing higher-order functions is through lambda functions.": [
                "higher-order",
                "lambda",
            ]
        },
    ),
    (
        "Pure functions simplify testing by eliminating dependencies on external state.",
        {},
        [],
        {
            "Pure functions simplify testing by eliminating dependencies on external state.": [],
        },
    ),
]


def mutate_globals():
    main_.keywords = []


def test(document, index, expected_keywords, expected_index):
    print("---------------------------------")
    print("Inputs:")
    print(f"* {document}")
    print(f"Index:")
    for key, value in index.items():
        print(f"  {key}: {value}")
    print(f"Expected Keywords: {expected_keywords}")
    print(f"Expected Index:")
    for key, value in expected_index.items():
        print(f"  {key}: {value}")
    index_copy = index.copy()
    result_keywords, result_index = main_.map_keywords(document, index)
    print(f"  Actual Keywords: {result_keywords}")
    print(f"  Actual Index:")
    for key, value in result_index.items():
        print(f"  {key}: {value}")
    if index_copy != index:
        print("Fail: Mutated input index")
        return False
    if index == expected_index and result_index != expected_index:
        print("Fail: Expected keywords from the input index")
        return False
    if len(result_keywords) == 0 and len(expected_keywords) != 0:
        print("Fail: the global scope keywords changed, causing this failure.")
        print("How can you use the keywords without them changing in the global scope?")
        return False
    if (result_keywords, result_index) != (expected_keywords, expected_index):
        print("Fail")
        return False
    print("Pass")
    return True


def main():
    test_cases = submit_cases
    if "__RUN__" in globals():
        test_cases = run_cases
    passed = 0
    failed = 0
    mutate_globals()
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


main()

