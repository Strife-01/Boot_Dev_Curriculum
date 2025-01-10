def zipmap(keys, values):
    if len(keys) == 0 or len(values) == 0:
        return {}
    curr_dict = {}
    curr_dict[keys[0]] = values[0]
    curr_dict = curr_dict | zipmap(keys[1:], values[1:])
    return curr_dict

