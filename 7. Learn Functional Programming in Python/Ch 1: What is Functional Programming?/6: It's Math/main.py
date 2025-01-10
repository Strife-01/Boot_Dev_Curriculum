def get_median_font_size(font_sizes):
    if len(font_sizes) == 0:
        return None
    if len(font_sizes) % 2 == 0:
        return sorted(font_sizes)[len(font_sizes) // 2 - 1]
    return sorted(font_sizes)[len(font_sizes) // 2]

