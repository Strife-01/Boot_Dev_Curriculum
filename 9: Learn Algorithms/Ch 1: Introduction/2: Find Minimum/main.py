def find_minimum(nums):
    if len(nums) == 0:
        return None
    min = float("inf")
    for num in nums:
        if num < min:
            min = num
    return min
