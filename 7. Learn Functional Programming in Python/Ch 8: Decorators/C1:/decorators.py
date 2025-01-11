def configure_plugin_decorator(func):
    def wrapper(*args):
        # def func(**kwargs)
        return func(**dict(args))
    return wrapper
