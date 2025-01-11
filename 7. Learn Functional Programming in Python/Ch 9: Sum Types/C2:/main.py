from enum import Enum


class EditType(Enum):
    NEWLINE = 1
    SUBSTITUTE = 2
    INSERT = 3
    DELETE = 4


def handle_edit(document, edit_type, edit):
    match edit_type:
        case EditType.NEWLINE:
            doc_cpy = document.split('\n')
            doc_cpy[edit["line_number"]] = f"{doc_cpy[edit['line_number']]}\n"
            return "\n".join(doc_cpy)
        case EditType.SUBSTITUTE:
            doc_cpy = document.split('\n')
            doc_cpy[edit["line_number"]] = doc_cpy[edit["line_number"]][:edit["start"]] + edit["insert_text"] + doc_cpy[edit["line_number"]][edit["end"]:]
            return "\n".join(doc_cpy)
        case EditType.INSERT:
            doc_cpy = document.split('\n')
            doc_cpy[edit["line_number"]] = doc_cpy[edit["line_number"]][:edit["start"]] + edit["insert_text"] + doc_cpy[edit["line_number"]][edit["start"]:]
            return "\n".join(doc_cpy)
        case EditType.DELETE:
            doc_cpy = document.split('\n')
            doc_cpy[edit["line_number"]] = doc_cpy[edit["line_number"]][:edit["start"]] + doc_cpy[edit["line_number"]][edit["end"]:]
            return "\n".join(doc_cpy)
        case _:
            raise Exception("Unknown edit type")
