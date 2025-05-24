import sys
import os
from stats import *

def get_book_text(file_path: str) -> str:
    with open(file_path, "r") as file:
        return f"{file.read()}"


def print_stats(file_path: str, word_count: int, char_hist_list: list[dict]) -> None:
    print("============ BOOKBOT ============")
    print(f"Analyzing book found at {file_path}")
    print("----------- Word Count ----------")
    print(f"Found {word_count} total words")
    print(f"--------- Character Count -------")
    for char_entry in char_hist_list:
        if not char_entry["char"].isalpha():
            continue
        print(f"{char_entry["char"]} {char_entry["num"]}")
    print("============= END ===============")


def main() -> None:
    # Check for correct usage
    if len(sys.argv) != 2:
        print('usage: python3 bookbot.pt <file>')
        sys.exit(1)
    elif not os.path.exists(sys.argv[1]):
        print('no such file or directory')
        sys.exit(2)

    filepath: str = sys.argv[1]
    file_contents: str = get_book_text(filepath)
    file_wordcount: int = get_num_words(file_contents)
    file_char_hist_list = get_sorted_list_dict_char(get_chr_histogram(file_contents))
    
    print_stats(filepath, file_wordcount, file_char_hist_list)

    sys.exit(0)

if __name__ == "__main__":
    main()
