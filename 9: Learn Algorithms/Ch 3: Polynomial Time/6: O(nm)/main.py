def get_avg_brand_followers(all_handles, brand_name):
    #return sum(list(map(lambda handles: len(handles) / len(list(filter(lambda handle: handle.__contains__(brand_name), handles))), all_handles))) / len(all_handles)
    total = 0
    for handles in all_handles:
        for handle in handles:
            if handle.__contains__(brand_name):
                total += 1
    return total / len(all_handles)
