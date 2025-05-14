#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
using namespace std;

class Library {
private:
    vector<Book> books;
    int levenshteinDistance(const string& s1, const string& s2) const;

public:
    void addBook(const Book& book);
    void showAllBooks() const;
    bool hasBook(const string& title) const;
    void removeBook(const string& title);
    int getBookCount() const;
    void editBook(const string& title,
        const string& newTitle,
        const string& newAuthor,
        const string& newYear,
        const string& newCategory);
    void sortBooksByTitle();
    void sortBooksByAuthor();
    vector<Book> searchBooks(const string& query, int threshold = 2) const;
};

#endif