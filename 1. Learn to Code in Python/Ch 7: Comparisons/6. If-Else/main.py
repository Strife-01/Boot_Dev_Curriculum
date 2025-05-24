def player_status(health):
    if health > 5:
        return "healthy"
    elif health > 0:
        return "injured"
    return "dead"

