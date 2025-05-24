def remove_nonints(nums):
    new_nums = []
    for n in nums:
        if type(n) is int:
            new_nums.append(n)
    return new_nums

