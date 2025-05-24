def find_min(nums):
    if not len(nums): return None
    min = float("inf")
    for n in nums:
        if n < min:
            min = n
    return min

