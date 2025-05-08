#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(const string& title, const string& author);
    string getTitle() const;
    string getAuthor() const;
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book);
    void showAllBooks() const;
    bool hasBook(const string& title) const;
};

#endif
