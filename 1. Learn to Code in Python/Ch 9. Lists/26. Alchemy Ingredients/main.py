def check_ingredient_match(recipe, ingredients):
    return len(list(filter(lambda item: item in ingredients, recipe))) / len(recipe) * 100, list(filter(lambda item: item not in ingredients, recipe))

