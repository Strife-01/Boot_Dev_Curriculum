from functools import reduce


def sum(nums):
    return 0 if len(nums) == 0 else reduce(lambda a, b: a + b, nums, 0)
