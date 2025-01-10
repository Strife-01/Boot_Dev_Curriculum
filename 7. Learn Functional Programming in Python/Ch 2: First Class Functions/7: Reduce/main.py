import functools


def join(doc_so_far, sentence):
    return f"{doc_so_far}. " + f"{sentence}"


def join_first_sentences(sentences, n):
    return f"{functools.reduce(join, sentences[:n]).strip()}." if n > 0 else ""

