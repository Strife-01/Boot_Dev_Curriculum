def quick_sort(nums, low, high):
    if low < high:
        pivot = partition(nums, low, high)
        quick_sort(nums, low, pivot - 1)
        quick_sort(nums, pivot + 1, high)


def partition(nums, low, high):
    j = low
    for i in range(low, high):
        if nums[i] < nums[high]:
            nums[i], nums[j] = nums[j], nums[i]
            j += 1
    nums[j], nums[high] = nums[high], nums[j]
    return j

