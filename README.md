# 圖書館管理系統

##  小專題介紹
這是一個用於管理書籍的簡單系統，包含新增書籍、顯示書籍和搜尋書籍等基本功能。

## 小組資料 & 分工

- **系級班級**：資訊工程學系 1B  
- **組別**：第11組  
- **組長**：陳格洋  
- **組員**：李晶沛、梁宇宏  
- **程式碼**：陳格洋
- **簡報製作**：李晶沛
- **上台報告**：梁宇宏

##  功能說明

- **新增書籍** - 可以將新書籍加入圖書館。

- **顯示所有書籍** - 列出圖書館中的所有書籍。

- **搜尋書籍** - 根據書名搜尋特定書籍。

- **退出系統** - 結束程式執行。

## 程式介紹
### - **Book 類別 (Book.h / Book.cpp)**
#### 用於表示書籍，包含以下屬性與方法：

#### 屬性：

> string title - 書名

> string author - 作者

#### 方法：

> Book(const string& t, const string& a) - 建構子

> string getTitle() const - 取得書名

> string getAuthor() const - 取得作者

> void display() const - 顯示書籍資訊

### - **Library 類別 (Library.h / Library.cpp)**
#### 管理書籍集合的類別。

屬性：

> vector<Book> books - 書籍列表

方法：

> void addBook(const Book& book) - 新增書籍

> void showAllBooks() const - 顯示所有書籍

> bool hasBook(const string& title) const - 判斷書籍是否存在

### - **Display 類別 (Display.h / Display.cpp)**
#### 負責與使用者互動的介面。

方法：

> void run(Library& library) const - 執行選單循環

> void showMenu() const - 顯示選單

> void promptForBookDetails(string& title, string& author) const - 提示輸入書名和作者


## 運行畫面截圖

![image](https://github.com/Ayak444/OOCSubjecct/edit/main/readme_repository/%E9%81%8B%E8%A1%8C%E7%95%AB%E9%9D%A2.png)
