#include "Display.h"
#include "Library.h"
#include "Book.h"
#include <iostream>
using namespace std;

void Display::showMenu() const {
    cout << "\n===== �Ϯ��]��� =====" << endl;
    cout << "1. �s�W���y" << endl;
    cout << "2. ��ܩҦ����y" << endl;
    cout << "3. �j�M���y" << endl;
    cout << "4. �R�����y" << endl;
    cout << "5. �ק���y" << endl;
    cout << "6. ���y�ƶq�έp" << endl;
    cout << "7. ���y�Ƨǡ]�ѦW�^" << endl;
    cout << "8. ���y�Ƨǡ]�@�̡^" << endl;
    cout << "0. ���}�t��" << endl;
    cout << "�п�J�A����ܡG";
}

void Display::promptForBookDetails(string& title, string& author, string& year, string& category) const {
    cout << "�п�J�ѦW�G";
    getline(cin, title);
    cout << "�п�J�@�̡G";
    getline(cin, author);
    cout << "�п�J�X���~���G";
    getline(cin, year);
    cout << "�п�J�����G";
    getline(cin, category);
}

void Display::run(Library& library) const {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
        case 1: {
            string title, author, year, category;
            promptForBookDetails(title, author, year, category);
            library.addBook(Book(title, author, year, category));
            cout << "���y�w�s�W�C" << endl;
            break;
        }
        case 2:
            library.showAllBooks();
            break;
        case 3: {
            string title;
            cout << "�п�J�n�j�M���ѦW�G";
            getline(cin, title);
            if (library.hasBook(title))
                cout << "���y�w���C" << endl;
            else
                cout << "�䤣����y�C" << endl;
            break;
        }
        case 4: {
            string title;
            cout << "�п�J�n�R�����ѦW�G";
            getline(cin, title);
            library.removeBook(title);
            break;
        }
        case 5: {
            string title, newTitle, newAuthor, newYear, newCategory;
            cout << "�п�J�n�ק諸�ѦW�G";
            getline(cin, title);
            cout << "�п�J�s�ѦW�G";
            getline(cin, newTitle);
            cout << "�п�J�s�@�̡G";
            getline(cin, newAuthor);
            cout << "�п�J�s�~���G";
            getline(cin, newYear);
            cout << "�п�J�s�����G";
            getline(cin, newCategory);
            library.editBook(title, newTitle, newAuthor, newYear, newCategory);
            break;
        }
        case 6:
            cout << "�Ϯ��]�ثe�@�� " << library.getBookCount() << " �����y�C" << endl;
            break;
        case 7:
            library.sortBooksByTitle();
            break;
        case 8:
            library.sortBooksByAuthor();
            break;
        case 0:
            cout << "�t�ΧY�N�h�X�A�P�¨ϥΡI" << endl;
            break;
        default:
            cout << "�L�Ī���ܡA�Э��s��J�C" << endl;
            break;
        }
    } while (choice != 0);
}
