class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author


class Library:
    def __init__(self, name):
        self.name = name
        self.books = []

    def add_book(self, book):
        self.books.append(book)

    def remove_book(self, book):
        for index, b in enumerate(self.books):
            if b.title == book.title and b.author == book.author:
                self.books = self.books[:index] + self.books[index + 1:]
                return

    def search_books(self, search_string):
        return_books = []
        for book in self.books:
            if search_string.lower() in book.title.lower():
                return_books.append(book)
        return return_books
    
