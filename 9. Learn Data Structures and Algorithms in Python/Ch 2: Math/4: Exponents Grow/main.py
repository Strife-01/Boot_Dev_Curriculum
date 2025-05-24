def get_follower_prediction(follower_count, influencer_type, num_months):
    match influencer_type:
        case "fitness":
            return follower_count * 4 ** num_months
        case "cosmetic":
            return follower_count * 3 ** num_months
        case _:
            return follower_count * 2 ** num_months

