def count_names(list_of_lists, target_name):
    count = 0
    for l in list_of_lists:
        for n in l:
            if n == target_name:
                count += 1
    return count
