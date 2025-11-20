#include <iostream>
#include "math.h"
#include <windows.h>

using namespace std;

/*
 * Главный файл программы
 * Использует функции из модуля математика
 * 
 * КОМПИЛЯЦИЯ:
 * g++ main.cpp math.cpp -o calculator
 * 
 * ЗАПУСК:
 * ./calculator (Linux/Mac)
 * calculator.exe (Windows)
 */

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=== КАЛЬКУЛЯТОР ===" << endl;
    
    int a = 10, b = 5;
    
    cout << "\nЧисла: a = " << a << ", b = " << b << endl;
    cout << "Сложение: " << add(a, b) << endl;
    cout << "Вычитание: " << subtract(a, b) << endl;
    cout << "Умножение: " << multiply(a, b) << endl;
    cout << "Деление: " << divide(a, b) << endl;
    cout << "Степень (2^3): " << power(2, 3) << endl;
    
    return 0;
}
