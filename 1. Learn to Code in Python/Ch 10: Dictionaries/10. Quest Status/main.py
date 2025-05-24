def get_quest_status(progress):
    for key, value in progress.items():
        if key == "bridge_run":
            return value["status"]
        elif type(value).__name__ == "dict":
            return get_quest_status(value)
