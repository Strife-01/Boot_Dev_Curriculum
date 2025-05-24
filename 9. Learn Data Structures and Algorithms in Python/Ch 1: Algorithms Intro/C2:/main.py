def median_followers(nums):
    return None if len(nums) == 0 else sorted(nums)[len(nums) // 2] if len(nums) % 2 == 1 else (sorted(nums)[len(nums) // 2 - 1] + sorted(nums)[len(nums) // 2]) / 2

