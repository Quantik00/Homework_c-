#include <iostream>
#include <string>
using namespace std;

struct Author {
    string firstName;
    string lastName;
};

struct Book {
    string title;
    Author author;
    int year;
    int pages;

    // инициализация по умолчанию
    Book() {
        title = "Неизвестно";
        author.firstName = "Неизвестно";
        author.lastName = "Неизвестно";
        year = 0;
        pages = 0;
    }

    // вывод информации о книге
    void displayBook() const {
        cout << "Название: " << title << endl;
        cout << "Имя автора: " << author.firstName << endl;
        cout << "Фамилия: " << author.lastName << endl;
        cout << "Год издания: " << year << endl;
        cout << "Количество страниц: " << pages << endl;
    }
};

// принимает данные о книге от пользователя
Book createBook() {
    Book newBook;
    
    cout << "Название книги: ";
    getline(cin, newBook.title);

    cout << "Имя автора: ";
    getline(cin, newBook.author.firstName);
    
    cout << "Фамилия автора: ";
    getline(cin, newBook.author.lastName);

    // Ввод года издания и количества страниц
    cout << "Год издания: ";
    cin >> newBook.year;

    cout << "Количество страниц: ";
    cin >> newBook.pages;

    return newBook;
}

int main()
{
    Book books[3];

    for (int i = 0; i < 3; i++) {
        cout << "Создать книгу (d - по умолчанию, c - ввод): ";
        char choice;
        cin >> choice;

        if (choice == 'c') {
            books[i] = createBook();
        } else {
            books[i] = Book(); // Инициализация книг значениями по умолчанию
        }
    }

    // Выводим информацию о книгах
    for (int i = 0; i < 3; i++) {
        cout << "Информация о книге #" << i + 1 << ":" << endl;
        books[i].displayBook();
    }

    return 0;
}
