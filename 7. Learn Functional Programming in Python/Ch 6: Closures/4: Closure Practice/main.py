def new_collection(initial_docs):
    col = initial_docs[:]
    def new_collection(doc):
        col.append(doc)
        return col
    return new_collection

