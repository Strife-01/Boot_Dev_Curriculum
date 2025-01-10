def destroy_walls(walls):
    for wall_health in walls:
        if wall_health <= 0:
            walls.remove(wall_health)
    return walls

