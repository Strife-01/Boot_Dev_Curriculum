def calculate_experience_points(level):
    return 0 if level == 1 else (level - 1) * 5 + calculate_experience_points(level - 1)

