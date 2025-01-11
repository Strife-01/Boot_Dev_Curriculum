def args_logger(*args, **kwargs):
    for index, arg in enumerate(args):
        print(f"{index + 1}. {arg}")
    for k, v in kwargs.items():
        print(f"* {k}: {v}")

