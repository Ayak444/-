#ifndef DISPLAY_H
#define DISPLAY_H

#include "Library.h"
#include <string>
using namespace std;

class Display {
public:
    void run(Library& library) const;
    void showMenu() const;
    void promptForBookDetails(string& title, string& author, string& year, string& category) const;
};

#endif
