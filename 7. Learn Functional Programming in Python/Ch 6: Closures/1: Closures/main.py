def word_count_aggregator():
    #count = {}
    count = 0
    def aggregator(doc):
        #for word in doc.split(" "):
            # here count in not a nonlocal cause we don't reassign the variable, we mutate the contents of it
            #count[word] = count.get(word, 0) + 1
        nonlocal count
        count += len(doc.split(' '))
        return count
    return aggregator

