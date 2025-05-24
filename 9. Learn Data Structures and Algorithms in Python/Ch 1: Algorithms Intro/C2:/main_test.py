from main import *

run_cases = [
    ([12, 12, 12], 12),
    ([10, 200, 3000, 5000, 4], 200),
    ([7, 4, 3, 100, 2343243, 343434, 1, 2, 32], 7),
    ([], None),
]

submit_cases = run_cases + [
    ([0], 0),
    ([1000000], 1000000),
    ([5, 2, 3, 7, 6, 4], 4.5),
    ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5.5),
]


def test(nums, expected_output):
    original_nums = nums.copy()
    print("---------------------------------")
    print(f"Input list: {nums}")
    print(f"Expecting: {expected_output}")
    result = median_followers(original_nums)
    print(f"Actual: {result}")
    if result == expected_output:
        print("Pass")
        return True
    print("Fail")
    return False


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

