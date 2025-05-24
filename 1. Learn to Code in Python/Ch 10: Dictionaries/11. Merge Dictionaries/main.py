def merge(dict1, dict2):
    for key, value in dict2.items():
        dict1[key] = value
    return dict1

