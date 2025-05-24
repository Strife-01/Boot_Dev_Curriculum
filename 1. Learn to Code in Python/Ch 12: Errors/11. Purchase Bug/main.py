def purchase_item(price, gold_available):
    if price > gold_available:
        raise Exception("not enough gold")
    return gold_available - price


