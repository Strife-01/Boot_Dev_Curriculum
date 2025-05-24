def destroy_walls(wall_health):
    h = []
    for w in wall_health:
        if w > 0:
            h.append(w)
    return h

