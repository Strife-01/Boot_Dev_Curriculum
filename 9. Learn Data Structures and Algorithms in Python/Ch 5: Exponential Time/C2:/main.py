def num_countries_in_days(max_days, factor):
    time_left = max_days
    count = 0
    time_in_country = 1
    
    while time_left > 0:
        time_left -= time_in_country * factor ** count
        count += 1

    if max_days > 1:
        return count - 1

    return count

