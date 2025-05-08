#include "Display.h"
#include <iostream>
using namespace std;

void Display::showMenu() const {
    cout << "\n===== �Ϯ��]��� =====" << endl;
    cout << "1. �s�W���y" << endl;
    cout << "2. ��ܩҦ����y" << endl;
    cout << "3. �j�M���y" << endl;
    cout << "0. ���}�t��" << endl;
    cout << "�п�J�A����ܡG";
}

void Display::promptForBookDetails(string& title, string& author) const {
    cout << "�п�J�ѦW�G";
    getline(cin, title);
    cout << "�п�J�@�̡G";
    getline(cin, author);
}

void Display::run(Library& library) const {
    int choice = -1;
    string title, author;

    while (choice != 0) {
        showMenu();
        cin >> choice;
        cin.ignore(); // �M������Ÿ�

        if (choice == 1) {
            promptForBookDetails(title, author);
            library.addBook(Book(title, author));
            cout << "���y�w�s�W�I\n";
        }
        else if (choice == 2) {
            library.showAllBooks();
        }
        else if (choice == 3) {
            cout << "�п�J�n�j�M���ѦW�G";
            getline(cin, title);
            if (library.hasBook(title)) {
                cout << "���y�y" << title << "�z�b�Ϯ��]���C\n";
            }
            else {
                cout << "���y�y" << title << "�z���b�Ϯ��]���C\n";
            }
        }
        else if (choice == 0) {
            cout << "�t�Τw�h�X�A�P�¨ϥΡI\n";
        }
        else {
            cout << "�L�Ī���ܡA�Э��s��J�C\n";
        }
    }
}
