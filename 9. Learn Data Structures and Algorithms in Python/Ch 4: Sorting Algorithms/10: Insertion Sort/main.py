def insertion_sort(nums):
    if len(nums) <= 1:
        return nums
    for j in range(1, len(nums)):
        for i in range(j - 1, -1, -1):
            if nums[i] <= nums[i + 1]:
                break
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
    return nums
