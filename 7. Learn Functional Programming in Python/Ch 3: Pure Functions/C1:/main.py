from copy import deepcopy as dc

default_commands = {}
default_formats = ["txt", "md", "html"]
saved_documents = {}

# Don't edit above this line


def add_custom_command(commands, new_command, function):
    com_copy = dc(commands)
    com_copy[new_command] = function
    return com_copy


def add_format(formats, format):
    form_copy = dc(formats)
    form_copy.append(format)
    return form_copy


def save_document(docs, file_name, doc):
    docs_copy = dc(docs)
    docs_copy[file_name] = doc
    return docs_copy


def add_line_break(line):
    return line + "\n\n"

