from math import log


def log_scale(data, base):
    return list(map(lambda d: log(d, base), data))
