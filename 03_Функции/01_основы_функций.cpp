/*
 * Урок 7: Функции
 * Тема: Объявление, определение и вызов функций
 */

#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

// Простая функция без параметров
void greet() {
    cout << "Привет из функции!" << endl;
}

// Функция с параметрами
void greetName(string name) {
    cout << "Привет, " << name << "!" << endl;
}

// Функция с возвращаемым значением
int add(int a, int b) {
    return a + b;
}

// Функция для вычисления площади прямоугольника
double rectangleArea(double length, double width) {
    return length * width;
}

// Функция для проверки четности
bool isEven(int number) {
    return number % 2 == 0;
}

// Функция с несколькими параметрами
void personInfo(string name, int age, string city) {
    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << endl;
    cout << "Город: " << city << endl;
}

// Функция для нахождения максимума
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// Функция для нахождения максимума из трех чисел
int maximum3(int a, int b, int c) {
    return maximum(maximum(a, b), c);
}

// Функция для вычисления факториала
long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функция для проверки простого numbers
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функция для вывода таблицы умножения
void multiplicationTable(int number) {
    cout << "Таблица умножения на " << number << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }
}

// Функция для конвертации температуры
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Вызов простой функции
    cout << "=== ПРОСТЫЕ ФУНКЦИИ ===" << endl;
    greet();
    greetName("Иван");

    // Функции с возвращаемым значением
    cout << "\n=== ФУНКЦИИ С ВОЗВРАТОМ ===" << endl;
    int sum = add(5, 3);
    cout << "5 + 3 = " << sum << endl;

    double area = rectangleArea(5.5, 3.2);
    cout << "Площадь прямоугольника: " << area << endl;

    // Проверка четности
    cout << "\n=== ПРОВЕРКА ЧЕТНОСТИ ===" << endl;
    int number = 7;
    if (isEven(number)) {
        cout << number << " - isEven" << endl;
    } else {
        cout << number << " - нечетное" << endl;
    }

    // Информация о человеке
    cout << "\n=== ИНФОРМАЦИЯ ===" << endl;
    personInfo("Мария", 25, "Москва");

    // Максимум
    cout << "\n=== МАКСИМУМ ===" << endl;
    cout << "Максимум из 10 и 20: " << maximum(10, 20) << endl;
    cout << "Максимум из 5, 15 и 10: " << maximum3(5, 15, 10) << endl;

    // Факториал
    cout << "\n=== ФАКТОРИАЛ ===" << endl;
    short int n = 5;
    cout << n << "! = " << factorial(n) << endl;

    // Простые numbers
    cout << "\n=== ПРОСТЫЕ ЧИСЛА ОТ 1 ДО 20 ===" << endl;
    for (int i = 1; i <= 20; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Таблица умножения
    cout << "\n=== ТАБЛИЦА УМНОЖЕНИЯ ===" << endl;
    multiplicationTable(7);

    // Конвертация температуры
    cout << "\n=== КОНВЕРТАЦИЯ ТЕМПЕРАТУРЫ ===" << endl;
    double temp = 25.0;
    cout << temp << "°C = " << celsiusToFahrenheit(temp) << "°F" << endl;
    cout << "77°F = " << fahrenheitToCelsius(77) << "°C" << endl;

    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте функцию для вычисления степени numbers
 * 2. Напишите функцию для проверки палиндрома (number читается одинаково)
 * 3. Создайте функцию для вычисления НОД (наибольший общий делитель)
 * 4. Напишите функцию для генерации случайного numbers в диапазоне
 */
