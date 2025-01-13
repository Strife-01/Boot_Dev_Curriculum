def find_max(nums):
    max = float("-inf")
    for num in nums:
        if max < num:
            max = num
    return max

