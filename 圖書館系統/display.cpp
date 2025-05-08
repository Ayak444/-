#include "Display.h"
#include <iostream>
using namespace std;

void Display::showMenu() const {
    cout << "\n===== 圖書館選單 =====" << endl;
    cout << "1. 新增書籍" << endl;
    cout << "2. 顯示所有書籍" << endl;
    cout << "3. 搜尋書籍" << endl;
    cout << "0. 離開系統" << endl;
    cout << "請輸入你的選擇：";
}

void Display::promptForBookDetails(string& title, string& author) const {
    cout << "請輸入書名：";
    getline(cin, title);
    cout << "請輸入作者：";
    getline(cin, author);
}

void Display::run(Library& library) const {
    int choice = -1;
    string title, author;

    while (choice != 0) {
        showMenu();
        cin >> choice;
        cin.ignore(); // 清除換行符號

        if (choice == 1) {
            promptForBookDetails(title, author);
            library.addBook(Book(title, author));
            cout << "書籍已新增！\n";
        }
        else if (choice == 2) {
            library.showAllBooks();
        }
        else if (choice == 3) {
            cout << "請輸入要搜尋的書名：";
            getline(cin, title);
            if (library.hasBook(title)) {
                cout << "書籍『" << title << "』在圖書館中。\n";
            }
            else {
                cout << "書籍『" << title << "』不在圖書館中。\n";
            }
        }
        else if (choice == 0) {
            cout << "系統已退出，感謝使用！\n";
        }
        else {
            cout << "無效的選擇，請重新輸入。\n";
        }
    }
}
