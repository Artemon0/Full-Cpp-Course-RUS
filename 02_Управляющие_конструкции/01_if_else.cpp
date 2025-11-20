/*
 * Урок 4: Условные операторы
 * Тема: if, else if, else
 */

#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Простой if
    cout << "=== ПРОСТОЙ IF ===" << endl;
    int age;
    cout << "Введите ваш age: ";
    cin >> age;
    
    if (age >= 18) {
        cout << "Вы совершеннолетний!" << endl;
    }
    
    // if-else
    cout << "\n=== IF-ELSE ===" << endl;
    int number;
    cout << "Введите number: ";
    cin >> number;
    
    if (number % 2 == 0) {
        cout << number << " - isEven number" << endl;
    } else {
        cout << number << " - нечетное number" << endl;
    }
    
    // if-else if-else
    cout << "\n=== IF-ELSE IF-ELSE ===" << endl;
    int grade;
    cout << "Введите оценку (0-100): ";
    cin >> grade;
    
    if (grade >= 90) {
        cout << "Отлично! Оценка: A" << endl;
    } else if (grade >= 80) {
        cout << "Хорошо! Оценка: B" << endl;
    } else if (grade >= 70) {
        cout << "Удовлетворительно. Оценка: C" << endl;
    } else if (grade >= 60) {
        cout << "Слабо. Оценка: D" << endl;
    } else {
        cout << "Неудовлетворительно. Оценка: F" << endl;
    }
    
    // Вложенные условия
    cout << "\n=== ВЛОЖЕННЫЕ УСЛОВИЯ ===" << endl;
    int temperature;
    bool isRaining;
    cout << "Введите температуру (°C): ";
    cin >> temperature;
    cout << "Идет isRaining? (1-да, 0-нет): ";
    cin >> isRaining;
    
    if (temperature > 25) {
        if (isRaining) {
            cout << "Тепло, но дождливо. Возьмите зонт!" << endl;
        } else {
            cout << "Отличная погода для прогулки!" << endl;
        }
    } else if (temperature > 15) {
        if (isRaining) {
            cout << "Прохладно и дождливо. Куртка и зонт!" << endl;
        } else {
            cout << "Прохладно, но приятно." << endl;
        }
    } else {
        if (isRaining) {
            cout << "Холодно и мокро. Лучше остаться дома!" << endl;
        } else {
            cout << "Холодно. Оденьтесь теплее!" << endl;
        }
    }
    
    // Тернарный оператор
    cout << "\n=== ТЕРНАРНЫЙ ОПЕРАТОР ===" << endl;
    int a, b;
    cout << "Введите два numbers: ";
    cin >> a >> b;
    
    int maximum = (a > b) ? a : b;
    cout << "Максимальное number: " << maximum << endl;
    
    // Практический пример: проверка високосного года
    cout << "\n=== ПРОВЕРКА ВИСОКОСНОГО ГОДА ===" << endl;
    int year;
    cout << "Введите year: ";
    cin >> year;
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " - високосный year!" << endl;
    } else {
        cout << year << " - не високосный year." << endl;
    }
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для определения категории водительских прав по возрасту
 * 2. Напишите калькулятор скидок (разные скидки для разных сумм покупки)
 * 3. Создайте программу для определения времени суток (утро, day, вечер, ночь)
 */
