def regenerate(current_health, max_health, enemy_distance):
    while enemy_distance > 3 and current_health < max_health:
        current_health += 1
        enemy_distance -= 2
    return current_health

