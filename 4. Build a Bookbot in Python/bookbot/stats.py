def get_num_words(book_text: str) -> int:
    return len(book_text.strip().split())


def get_chr_histogram(book_text: str) -> dict[str, int]:
    hist = dict()
    for c in book_text.lower():
        hist[c] = hist.get(c, 0) + 1
    return hist


def get_sorted_list_dict_char(chr_histogram: dict[str, int]) -> list[dict]:
    hist_list = list()
    for char, count in chr_histogram.items():
        hist_list.append({"char": char, "num": count})
    hist_list.sort(key=lambda hist_entry: hist_entry["num"], reverse=True)
    return hist_list
