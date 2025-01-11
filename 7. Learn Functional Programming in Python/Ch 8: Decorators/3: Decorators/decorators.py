def markdown_to_text_decorator(func):
    def wrapper(*args, **kwargs):
        list_args = list(map(convert_md_to_txt, args))
        dict_args = list(map(lambda t: convert_md_to_txt(t[1]), kwargs.items()))
        return func(*list_args, *dict_args)
    return wrapper


# don't touch below this line


def convert_md_to_txt(doc):
    lines = doc.split("\n")
    for i in range(len(lines)):
        line = lines[i]
        lines[i] = line.lstrip("# ")
    return "\n".join(lines)

