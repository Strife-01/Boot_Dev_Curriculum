def remove_invalid_lines(document):
    return "\n".join(filter(lambda line: False if line.startswith('-') else True, document.split('\n')))

