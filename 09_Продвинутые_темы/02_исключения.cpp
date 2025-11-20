/*
 * Урок 2: Исключения (Exceptions)
 * Тема: Обработка ошибок
 */

#include <iostream>
#include <stdexcept>
#include <windows.h>
using namespace std;

// Функция с проверкой деления на ноль
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Деление на ноль!");
    }
    return a / b;
}

// Функция проверки возраста
void проверитьВозраст(int age) {
    if (age < 0) {
        throw invalid_argument("Возраст не может быть отрицательным!");
    }
    if (age > 150) {
        throw out_of_range("Возраст слишком большой!");
    }
    cout << "Возраст корректен: " << age << endl;
}

// Класс с собственным исключением
class BankException : public exception {
private:
    string message;
    
public:
    BankException(string msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Счет {
private:
    double balance;
    
public:
    Счет(double initialBalance) : balance(initialBalance) {}
    
    void withdraw(double sum) {
        if (sum < 0) {
            throw BankException("Сумма не может быть отрицательной!");
        }
        if (sum > balance) {
            throw BankException("Недостаточно средств на счете!");
        }
        balance -= sum;
        cout << "Снято: " << sum << " руб." << endl;
    }
    
    double getBalance() { return balance; }
};

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Базовая обработка исключений
    cout << "=== БАЗОВАЯ ОБРАБОТКА ===" << endl;
    try {
        double result = divide(10, 2);
        cout << "Результат: " << result << endl;
        
        result = divide(10, 0);  // Вызовет исключение
        cout << "Эта row не выполнится" << endl;
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Множественные типы исключений
    cout << "\n=== МНОЖЕСТВЕННЫЕ ИСКЛЮЧЕНИЯ ===" << endl;
    try {
        проверитьВозраст(25);
        проверитьВозраст(-5);
    }
    catch (const invalid_argument& e) {
        cout << "Неверный аргумент: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "Вне диапазона: " << e.what() << endl;
    }
    
    // Собственные исключения
    cout << "\n=== СОБСТВЕННЫЕ ИСКЛЮЧЕНИЯ ===" << endl;
    try {
        Счет account(1000);
        cout << "Баланс: " << account.getBalance() << " руб." << endl;
        
        account.withdraw(500);
        cout << "Баланс: " << account.getBalance() << " руб." << endl;
        
        account.withdraw(1000);  // Вызовет исключение
    }
    catch (const BankException& e) {
        cout << "Банковская ошибка: " << e.what() << endl;
    }
    
    // Блок finally (через деструктор)
    cout << "\n=== ГАРАНТИРОВАННОЕ ВЫПОЛНЕНИЕ ===" << endl;
    try {
        cout << "Начало операции" << endl;
        throw runtime_error("Тестовая ошибка");
        cout << "Эта row не выполнится" << endl;
    }
    catch (...) {  // Ловит все исключения
        cout << "Поймано любое исключение" << endl;
    }
    cout << "Завершение программы" << endl;
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте функцию для безопасного ввода numbers с обработкой ошибок
 * 2. Создайте класс Массив с проверкой границ и исключениями
 * 3. Создайте систему обработки ошибок для калькулятора
 */
