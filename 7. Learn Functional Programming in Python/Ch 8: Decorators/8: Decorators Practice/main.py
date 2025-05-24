def replacer(old, new):
    def replace(decorated_func):
        def wrapper(text):
            return decorated_func(text.replace(old, new))
        return wrapper
    return replace


@replacer("&", "&amp;")
@replacer("<", "&lt;")
@replacer(">", "&gt;")
@replacer('"', "&quot;")
@replacer("'", "&#x27;")
def tag_pre(text):
    return f"<pre>{text}</pre>"

