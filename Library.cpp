#include "Library.h"
#include <algorithm>
#include <iostream>
using namespace std;

void Library::addBook(const Book& book) { books.push_back(book); }

void Library::showAllBooks() const {
    if (books.empty()) {
        cout << "圖書館中沒有書籍。" << endl;
        return;
    }
    for (const auto& book : books) {
        book.display();
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

void Library::removeBook(const string& title) {
    books.erase(remove_if(books.begin(), books.end(), [&](const Book& b) {
        return b.getTitle() == title;
        }), books.end());
    cout << "書籍『" << title << "』已刪除。" << endl;
}

int Library::getBookCount() const { return books.size(); }

void Library::editBook(const string& title, const string& newTitle, const string& newAuthor, const string& newYear, const string& newCategory) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            book.setTitle(newTitle);
            book.setAuthor(newAuthor);
            book.setYear(newYear);
            book.setCategory(newCategory);
            cout << "書籍資訊已更新。" << endl;
            return;
        }
    }
    cout << "找不到要修改的書籍。" << endl;
}

void Library::sortBooksByTitle() {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
        });
    cout << "書籍已按書名排序。" << endl;
}

void Library::sortBooksByAuthor() {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getAuthor() < b.getAuthor();
        });
    cout << "書籍已按作者排序。" << endl;
}
