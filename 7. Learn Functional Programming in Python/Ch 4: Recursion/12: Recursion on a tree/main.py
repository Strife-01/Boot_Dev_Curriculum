def list_files(parent_directory, current_filepath=""):
    if not isinstance(parent_directory, dict):
        return [f"{current_filepath}/{parent_directory.values()[0]}"]
    curr_file_paths_list = []
    for pd, child in parent_directory.items():
        if child == None:
            curr_file_paths_list.append(f"{current_filepath}/{pd}")
        else:
            curr_file_paths_list += list_files(child, f"{current_filepath}/{pd}")
    return curr_file_paths_list
