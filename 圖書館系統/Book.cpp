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
    cout << "�ѦW�G" << title << "�A�@�̡G" << author << endl;
}
