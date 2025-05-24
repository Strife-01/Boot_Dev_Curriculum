def check_mount_rental(time_used, time_purchased):
    return "overtime charged" if time_used >= time_purchased else "no charges yet"

