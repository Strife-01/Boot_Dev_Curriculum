def merge_sort(nums):
    if len(nums) < 2:
        return nums
    first = merge_sort(nums[:len(nums) // 2])
    second = merge_sort(nums[len(nums) // 2:])
    return merge(first, second)


def merge(first, second):
    i = 0
    j = 0
    arr = []

    while i < len(first) and j < len(second):
        if first[i] < second[j]:
            arr.append(first[i])
            i += 1
        else:
            arr.append(second[j])
            j += 1

    while i < len(first):
        arr.append(first[i])
        i += 1

    while j < len(second):
        arr.append(second[j])
        j += 1

    return arr
