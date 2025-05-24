def does_name_exist(first_names, last_names, full_name):
    for f_name in first_names:
        for l_name in last_names:
            if f"{f_name} {l_name}" == full_name:
                return True
    return False

