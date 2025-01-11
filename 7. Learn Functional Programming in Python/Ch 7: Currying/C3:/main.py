def new_resizer(max_width, max_height):
    def inner(min_width=0, min_height=0):
        if min_height > max_height or min_width > max_width:
            raise Exception("minimum size cannot exceed maximum size")
        def inner_most(width, height):
            return min(max(width, min_width), max_width), min(max(height, min_height), max_height)
        return inner_most
    return inner

