def power_set(input_set):
    if len(input_set) == 0:
        return [[]]
    l = []
    rl = power_set(input_set[1:])
    for ll in rl:
        l.append([input_set[0]] + ll)
        l.append(ll)
    return l
