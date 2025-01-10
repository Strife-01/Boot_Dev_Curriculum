def toggle_case(line):
    if line.istitle():
        return f"{line.upper()}!!!"
    if line.isupper():
        return line.strip('!').lower().capitalize()
    if len(line) > 0 and line[1:].islower():
        return line.title()
    return line

