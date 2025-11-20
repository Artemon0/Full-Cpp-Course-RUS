/*
 * Урок 5: Циклы
 * Тема: for, while, do-while
 */

#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Цикл FOR
    cout << "=== ЦИКЛ FOR ===" << endl;
    cout << "Числа от 1 до 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Таблица умножения
    cout << "\nТаблица умножения на 5:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "5 x " << i << " = " << (5 * i) << endl;
    }

    // Цикл WHILE
    cout << "\n=== ЦИКЛ WHILE ===" << endl;
    int counter = 1;
    cout << "Четные numbers от 2 до 20:" << endl;
    while (counter <= 10) {
        cout << (counter * 2) << " ";
        counter++;
    }
    cout << endl;

    // Цикл DO-WHILE
    cout << "\n=== ЦИКЛ DO-WHILE ===" << endl;
    int number;
    do {
        cout << "Введите положительное number (0 для выхода): ";
        cin >> number;
        if (number > 0) {
            cout << "Квадрат numbers: " << (number * number) << endl;
        }
    } while (number != 0);

    // Вложенные циклы
    cout << "\n=== ВЛОЖЕННЫЕ ЦИКЛЫ ===" << endl;
    cout << "Таблица умножения:" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << (i * j) << "\t";
        }
        cout << endl;
    }

    // Break и Continue
    cout << "\n=== BREAK И CONTINUE ===" << endl;
    cout << "Числа от 1 до 10, пропуская 5:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue; // Пропустить 5
        }
        cout << i << " ";
    }
    cout << endl;

    cout << "\nЧисла от 1 до 10, остановка на 7:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 7) {
            break; // Выйти из цикла
        }
        cout << i << " ";
    }
    cout << endl;

    // Практический пример: sum чисел
    cout << "\n=== СУММА ЧИСЕЛ ===" << endl;
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int temp;
        cout << "Число " << i << ": ";
        cin >> temp;
        sum += temp;
    }
    cout << "Сумма всех чисел: " << sum << endl;
    cout << "Среднее value: " << (double) sum / n << endl;

    // Факториал
    cout << "\n=== ФАКТОРИАЛ ===" << endl;
    int num;
    cout << "Введите number для вычисления факториала: ";
    cin >> num;

    long long factorial = 1;
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }
    cout << num << "! = " << factorial << endl;

    // Рисование треугольника
    cout << "\n=== ТРЕУГОЛЬНИК ИЗ ЗВЕЗДОЧЕК ===" << endl;
    int height;
    cout << "Введите высоту треугольника: ";
    cin >> height;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для вывода чисел Фибоначчи
 * 2. Напишите программу для проверки, является ли number простым
 * 3. Создайте программу для реверса numbers (123 -> 321)
 * 4. Нарисуйте пирамиду из звездочек
 */
