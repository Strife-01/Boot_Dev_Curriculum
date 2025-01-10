def sort_dates(dates):
    # MM-DD-YYYY
    sorted_dates = sorted(dates, key=lambda date: tuple(date.split('-')[2:] + date.split('-')[:2]))
    return sorted_dates

