# estimated_spread = average_audience_followers * ( num_followers ^ 1.2 )
def get_estimated_spread(audiences_followers):
    return 0 if len(audiences_followers) == 0 else sum(audiences_followers) / len(audiences_followers) * len(audiences_followers) ** 1.2

