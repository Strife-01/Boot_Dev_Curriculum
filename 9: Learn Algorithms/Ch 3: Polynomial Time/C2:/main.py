def remove_duplicates(nums):
    visited = {}
    nums_to_return = []
    for num in nums:
        if num not in visited:
            nums_to_return.append(num)
            visited[num] = True
    del visited
    return nums_to_return

