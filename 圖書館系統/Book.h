#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string year;
    string category;

public:
    Book(const string& t, const string& a, const string& y, const string& c);
    string getTitle() const;
    string getAuthor() const;
    string getYear() const;
    string getCategory() const;
    void setTitle(const string& t);
    void setAuthor(const string& a);
    void setYear(const string& y);
    void setCategory(const string& c);
    void display() const;
};

#endif
