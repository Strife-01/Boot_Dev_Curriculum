def sum_nested_list(lst):
    curr_sum = 0
    for elem in lst:
        if not isinstance(elem, list):
            curr_sum += elem
        else:
            curr_sum += sum_nested_list(elem)
    return curr_sum
