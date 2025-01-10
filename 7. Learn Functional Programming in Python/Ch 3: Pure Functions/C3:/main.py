from copy import deepcopy as dc


def map_keywords(document, document_map):
    document_map_copy = dc(document_map)
    if document in document_map_copy:
        return document_map_copy[document], document_map_copy
    document_map_copy[document] = find_keywords(document)
    return document_map_copy[document], document_map_copy


def find_keywords(document):
    keywords = [
        "functional",
        "immutable",
        "declarative",
        "higher-order",
        "lambda",
        "deterministic",
        "side-effects",
        "memoization",
        "referential transparency",
    ]
    
    kws = []
    for kw in keywords:
        if (index := document.find(kw)) != -1:
            kws.append(kw)
    return kws
