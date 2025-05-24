def filter_messages(messages):
    fr = []
    new_messages = []
    for message in messages:
        f = 0
        cur_message = []
        for m in message.split():
            if m == "dang":
                f += 1
            else:
                cur_message += [m]
        new_messages += [" ".join(cur_message)]
        fr += [f]

    return new_messages, fr

