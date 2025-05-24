from queue import Queue


def matchmake(queue, user):
    if user[1] == 'leave':
        queue.search_and_remove(user[0])
    else:
        queue.push(user[0])
    return "No match found" if queue.size() < 4 else f"{queue.pop()} matched {queue.pop()}!"

