/*
 * Урок 6: Оператор Switch
 * Тема: Множественный choice
 */

#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Простой switch
    cout << "=== МЕНЮ ВЫБОРА ===" << endl;
    short int choice;
    cout << "1. Кофе" << endl;
    cout << "2. Чай" << endl;
    cout << "3. Сок" << endl;
    cout << "4. Вода" << endl;
    cout << "Ваш choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "Вы выбрали кофе. Цена: 150 руб." << endl;
            break;
        case 2:
            cout << "Вы выбрали чай. Цена: 100 руб." << endl;
            break;
        case 3:
            cout << "Вы выбрали сок. Цена: 120 руб." << endl;
            break;
        case 4:
            cout << "Вы выбрали воду. Цена: 50 руб." << endl;
            break;
        default:
            cout << "Неверный choice!" << endl;
    }
    
    // Калькулятор с switch
    cout << "\n=== КАЛЬКУЛЯТОР ===" << endl;
    double a, b;
    char operation;
    
    cout << "Введите первое number: ";
    cin >> a;
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;
    cout << "Введите второе number: ";
    cin >> b;
    
    switch (operation) {
        case '+':
            cout << "Результат: " << (a + b) << endl;
            break;
        case '-':
            cout << "Результат: " << (a - b) << endl;
            break;
        case '*':
            cout << "Результат: " << (a * b) << endl;
            break;
        case '/':
            if (b != 0) {
                cout << "Результат: " << (a / b) << endl;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
            }
            break;
        default:
            cout << "Неизвестная operation!" << endl;
    }
    
    // Дни недели
    cout << "\n=== ДНИ НЕДЕЛИ ===" << endl;
    int day;
    cout << "Введите номер дня (1-7): ";
    cin >> day;
    
    switch (day) {
        case 1:
            cout << "Понедельник - начало рабочей недели" << endl;
            break;
        case 2:
            cout << "Вторник" << endl;
            break;
        case 3:
            cout << "Среда - середина недели" << endl;
            break;
        case 4:
            cout << "Четверг" << endl;
            break;
        case 5:
            cout << "Пятница - последний рабочий day!" << endl;
            break;
        case 6:
            cout << "Суббота - выходной!" << endl;
            break;
        case 7:
            cout << "Воскресенье - выходной!" << endl;
            break;
        default:
            cout << "Такого дня не существует!" << endl;
    }
    
    // Группировка case (без break)
    cout << "\n=== ОПРЕДЕЛЕНИЕ ТИПА ДНЯ ===" << endl;
    cout << "Введите номер дня (1-7): ";
    cin >> day;
    
    switch (day) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Это рабочий day" << endl;
            break;
        case 6:
        case 7:
            cout << "Это выходной day!" << endl;
            break;
        default:
            cout << "Неверный номер дня" << endl;
    }
    
    // Оценки
    cout << "\n=== СИСТЕМА ОЦЕНОК ===" << endl;
    char grade;
    cout << "Введите оценку (A, B, C, D, F): ";
    cin >> grade;
    
    switch (grade) {
        case 'A':
        case 'a':
            cout << "Отлично! 90-100 баллов" << endl;
            break;
        case 'B':
        case 'b':
            cout << "Хорошо! 80-89 баллов" << endl;
            break;
        case 'C':
        case 'c':
            cout << "Удовлетворительно. 70-79 баллов" << endl;
            break;
        case 'D':
        case 'd':
            cout << "Слабо. 60-69 баллов" << endl;
            break;
        case 'F':
        case 'f':
            cout << "Неудовлетворительно. Меньше 60 баллов" << endl;
            break;
        default:
            cout << "Неверная grade!" << endl;
    }
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте меню ресторана с ценами и описанием блюд
 * 2. Напишите конвертер валют (доллар, евро, рубль)
 * 3. Создайте программу для определения времени года по номеру месяца
 * 4. Сделайте простую игру "Выбери свое приключение"
 */
