/*
 * Урок 1: Классы и объекты
 * Тема: Основы объектно-ориентированного программирования
 */

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Простой класс
class Person {
public:
    // Поля (атрибуты)
    string name;
    int age;
    
    // Методы
    void introduce() {
        cout << "Привет! Меня зовут " << name << ", мне " << age << " лет." << endl;
    }
    
    void birthday() {
        age++;
        cout << name << " теперь " << age << " лет!" << endl;
    }
};

// Класс с конструктором
class Rectangle {
private:
    double width;
    double height;
    
public:
    // Конструктор
    Rectangle(double ш, double в) {
        width = ш;
        height = в;
    }
    
    // Методы
    double area() {
        return width * height;
    }
    
    double perimeter() {
        return 2 * (width + height);
    }
    
    void show() {
        cout << "Rectangle: " << width << " x " << height << endl;
        cout << "Площадь: " << area() << endl;
        cout << "Периметр: " << perimeter() << endl;
    }
};

// Класс банковский account
class BankAccount {
private:
    string owner;
    double balance;
    
public:
    // Конструктор
    BankAccount(string name, double initialBalance = 0) {
        owner = name;
        balance = initialBalance;
    }
    
    // Пополнение счета
    void deposit(double sum) {
        if (sum > 0) {
            balance += sum;
            cout << "Счет пополнен на " << sum << " руб." << endl;
        }
    }
    
    // Снятие денег
    void withdraw(double sum) {
        if (sum > 0 && sum <= balance) {
            balance -= sum;
            cout << "Снято " << sum << " руб." << endl;
        } else {
            cout << "Недостаточно средств!" << endl;
        }
    }
    
    // Показать balance
    void showBalance() {
        cout << "Владелец: " << owner << endl;
        cout << "Баланс: " << balance << " руб." << endl;
    }
};

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание объектов класса Person
    cout << "=== КЛАСС ЧЕЛОВЕК ===" << endl;
    Person человек1;
    человек1.name = "Иван";
    человек1.age = 25;
    человек1.introduce();
    человек1.birthday();
    
    // Создание объекта класса Rectangle
    cout << "\n=== КЛАСС ПРЯМОУГОЛЬНИК ===" << endl;
    Rectangle прям(5.0, 3.0);
    прям.show();
    
    // Создание объекта класса BankAccount
    cout << "\n=== БАНКОВСКИЙ СЧЕТ ===" << endl;
    BankAccount account("Мария", 1000);
    account.showBalance();
    account.deposit(500);
    account.withdraw(300);
    account.showBalance();
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте класс Student с полями: name, курс, средний score
 * 2. Создайте класс Книга с методами для выдачи и возврата
 * 3. Создайте класс Калькулятор с методами для основных операций
 */
