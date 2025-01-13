"""
This problem is known as the Subset Sum Problem, which is an NP-hard problem.
It asks the question, "Can we pick numbers from a list to add up to a target number?"
"""


"""
def subset_sum(nums, target):
    for s in power_set(nums):
        if sum(s) == target:
            return True
    return False
"""
def subset_sum(nums, target):
    return find_subset_sum(nums, target, len(nums) - 1)


def find_subset_sum(nums, target, index):
    if target == 0:
        return True
    if index < 0 and target != 0:
        return False
    if nums[index] > target:
        return find_subset_sum(nums, target, index - 1)
    else:
        r = find_subset_sum(nums, target, index - 1)
        s = find_subset_sum(nums, target - nums[index], index - 1)
        if r == True or s == True:
            return True
        return False


"""
def power_set(nums):
    if len(nums) == 0:
        return [[]]
    ps = []
    curr_sets = power_set(nums[1:])
    for s in curr_sets:
        ps.append(s)
        ps.append([nums[0]] + s)
    return ps
"""
