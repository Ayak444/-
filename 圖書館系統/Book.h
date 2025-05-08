#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(const string& t, const string& a);
    string getTitle() const;
    string getAuthor() const;
    void display() const;
};

#endif
