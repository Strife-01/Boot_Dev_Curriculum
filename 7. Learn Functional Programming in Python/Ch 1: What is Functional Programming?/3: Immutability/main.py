def add_prefix(document, documents):
    prefix = f"{len(documents)}. "
    new_doc = prefix + document
    return (*documents, new_doc)

