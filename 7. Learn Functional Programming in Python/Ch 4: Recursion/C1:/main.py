def count_nested_levels(nested_documents, target_document_id, level=1):
    for doc_id in nested_documents.keys():
        if doc_id == target_document_id:
            return level
        found_level = count_nested_levels(nested_documents[doc_id], target_document_id, level + 1)
        if found_level != -1:
            return found_level
    return -1
