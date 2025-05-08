#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(const string& t, const string& a) : title(t), author(a) {}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

void Book::display() const {
    cout << "書名：" << title << "，作者：" << author << endl;
}
