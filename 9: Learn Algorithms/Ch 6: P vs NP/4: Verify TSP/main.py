def verify_tsp(paths, dist, actual_path):
    sum = 0
    for i in range(len(actual_path) - 1):
        sum += paths[actual_path[i]][actual_path[i + 1]]
    return sum <= dist

