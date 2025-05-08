#include "Library.h"
#include <iostream>
using namespace std;

Book::Book(const string& title, const string& author)
    : title(title), author(author) {
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::showAllBooks() const {
    if (books.empty()) {
        cout << "圖書館中沒有書籍。" << endl;
        return;
    }

    for (const auto& book : books) {
        cout << "書名：" << book.getTitle()
            << "，作者：" << book.getAuthor() << endl;
    }
}

bool Library::hasBook(const string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            return true;
        }
    }
    return false;
}
