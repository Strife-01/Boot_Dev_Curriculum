def restore_documents(originals, backups):
    return set(list(filter(lambda doc: not(doc.isdigit()), map(lambda doc: doc.upper(), originals))) + list(filter(lambda bkp: not(bkp.isdigit()), map(lambda doc: doc.upper(), backups))))

