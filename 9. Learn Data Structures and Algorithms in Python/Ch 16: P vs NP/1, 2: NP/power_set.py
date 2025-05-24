def power_set(l):
    if len(l) == 0:
        return [[]]
    lr = power_set(l[1:])
    ret_l = []
    for ll in lr:
        ret_l.append([l[0]] + ll)
        ret_l.append(ll)
    return ret_l
