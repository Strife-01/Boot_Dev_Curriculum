def count_enemies(enemy_names):
    enemies_dict = {}
    for enemy_name in enemy_names:
        enemies_dict[enemy_name] = enemies_dict.get(enemy_name, 0) + 1
    return enemies_dict

