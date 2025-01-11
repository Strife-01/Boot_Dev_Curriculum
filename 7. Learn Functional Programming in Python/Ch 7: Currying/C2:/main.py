def create_markdown_image(alt_text):
    img = f"![{alt_text}]"
    def inner_function(url):
        nonlocal img
        url = url.replace('(', '%28')
        url = url.replace(')', '%29')
        img += f"({url})"
        def inner_most_function(title=""):
            nonlocal img
            if title != "":
                img = img.replace(')', f' "{title}")')
            return img
        return inner_most_function
    return inner_function
