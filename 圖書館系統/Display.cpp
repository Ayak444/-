#include "Display.h"
#include "Library.h"
#include <iostream>

using namespace std;

void Display::showMenu() const {
    cout << "\n===== 圖書館選單 =====" << endl;
    cout << "1. 新增書籍" << endl;
    cout << "2. 顯示所有書籍" << endl;
    cout << "3. 搜尋書籍（模糊搜尋）" << endl;
    cout << "4. 刪除書籍" << endl;
    cout << "5. 修改書籍" << endl;
    cout << "6. 書籍數量統計" << endl;
    cout << "7. 書籍排序（書名）" << endl;
    cout << "8. 書籍排序（作者）" << endl;
    cout << "0. 離開系統" << endl;
    cout << "請輸入你的選擇：";
}

void Display::promptForBookDetails(string& title, string& author, string& year, string& category) const {
    cout << "請輸入書名：";
    getline(cin, title);
    cout << "請輸入作者：";
    getline(cin, author);
    cout << "請輸入出版年份：";
    getline(cin, year);
    cout << "請輸入分類：";
    getline(cin, category);
}

void Display::run(Library& library) const {
    int choice = -1;
    while (choice != 0) {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            string title, author, year, category;
            promptForBookDetails(title, author, year, category);
            library.addBook(Book(title, author, year, category));
            cout << "書籍已新增。" << endl;
            break;
        }
        case 2:
            library.showAllBooks();
            break;
        case 3: {
            string query;
            cout << "請輸入要搜尋的書名或關鍵字：";
            getline(cin, query);
            auto results = library.searchBooks(query);
            if (results.empty()) {
                cout << "找不到相關書籍。" << endl;
            }
            else {
                cout << "找到 " << results.size() << " 本相關書籍：" << endl;
                for (const auto& b : results) {
                    b.display();
                }
            }
            break;
        }
        case 4: {
            string title;
            cout << "請輸入要刪除的書名：";
            getline(cin, title);
            library.removeBook(title);
            break;
        }
        case 5: {
            string title, newTitle, newAuthor, newYear, newCategory;
            cout << "請輸入要修改的書名：";
            getline(cin, title);
            cout << "請輸入新書名：";
            getline(cin, newTitle);
            cout << "請輸入新作者：";
            getline(cin, newAuthor);
            cout << "請輸入新年份：";
            getline(cin, newYear);
            cout << "請輸入新分類：";
            getline(cin, newCategory);
            library.editBook(title, newTitle, newAuthor, newYear, newCategory);
            break;
        }
        case 6:
            cout << "圖書館目前共有 " << library.getBookCount() << " 本書籍。" << endl;
            break;
        case 7:
            library.sortBooksByTitle();
            break;
        case 8:
            library.sortBooksByAuthor();
            break;
        case 0:
            cout << "系統即將退出，感謝使用！" << endl;
            break;
        default:
            cout << "無效的選擇，請重新輸入。" << endl;
            break;
        }
    }
}