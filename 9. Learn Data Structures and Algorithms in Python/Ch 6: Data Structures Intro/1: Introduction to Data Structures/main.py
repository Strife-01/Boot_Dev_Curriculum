def count_marketers(job_titles):
    return len(list(filter(lambda job: job == "marketer", job_titles)))

