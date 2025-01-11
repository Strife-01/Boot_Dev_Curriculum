from copy import deepcopy as dp


def new_clipboard(initial_clipboard):
    clipboard = dp(initial_clipboard)
    def copy_to_clipboard(key, value):
        clipboard[key] = value
    
    def paste_from_clipboard(key):
        return clipboard.get(key, "")

    return copy_to_clipboard, paste_from_clipboard

