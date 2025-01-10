def convert_case(text, target_format):
    if not text or not target_format:
        raise ValueError(f"No text or target format provided")

    if target_format == "uppercase":
        print(text.upper())
        return text.upper()
    if target_format == "lowercase":
        print(text.lower())
        return text.lower()
    if target_format == "titlecase":
        print(text.title())
        return text.title()
    raise ValueError(f"Unsupported format: {target_format}")

