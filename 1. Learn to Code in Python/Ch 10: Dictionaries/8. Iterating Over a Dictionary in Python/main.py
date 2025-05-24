def get_most_common_enemy(enemies_dict):
    most_common_num = float("-inf")
    most_common_enemy = None
    for enemy, apperaces in enemies_dict.items():
        if apperaces > most_common_num:
            most_common_num = apperaces
            most_common_enemy = enemy
    return most_common_enemy

