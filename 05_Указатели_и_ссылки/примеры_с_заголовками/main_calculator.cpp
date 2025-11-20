#include <iostream>
#include <windows.h>
#include "Calculator.h"

using namespace std;

/*
 * Пример использования класса Calculator
 * Демонстрирует работу с заголовочными файлами
 * 
 * КОМПИЛЯЦИЯ:
 * g++ main_calculator.cpp Calculator.cpp -o calculator
 * 
 * ЗАПУСК:
 * ./calculator (Linux/macOS)
 * calculator.exe (Windows)
 */

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║   ДЕМОНСТРАЦИЯ КЛАССА CALCULATOR       ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Создание объекта калькулятора
    Calculator calc;
    cout << endl;
    
    // Базовые операции
    cout << "=== БАЗОВЫЕ ОПЕРАЦИИ ===" << endl;
    cout << "10 + 5 = " << calc.add(10, 5) << endl;
    cout << "10 - 5 = " << calc.subtract(10, 5) << endl;
    cout << "10 * 5 = " << calc.multiply(10, 5) << endl;
    cout << "10 / 5 = " << calc.divide(10, 5) << endl;
    cout << endl;
    
    // Дополнительные операции
    cout << "=== ДОПОЛНИТЕЛЬНЫЕ ОПЕРАЦИИ ===" << endl;
    cout << "2^8 = " << calc.power(2, 8) << endl;
    cout << "√16 = " << calc.squareRoot(16) << endl;
    cout << "20% от 150 = " << calc.percentage(150, 20) << endl;
    cout << endl;
    
    // Использование геттеров
    cout << "=== ИНФОРМАЦИЯ ===" << endl;
    cout << "Последний результат: " << calc.getLastResult() << endl;
    cout << "Выполнено операций: " << calc.getOperationCount() << endl;
    cout << endl;
    
    // Inline функция
    cout << "=== INLINE ФУНКЦИЯ ===" << endl;
    double number = -5.5;
    cout << "Число " << number << " положительное? " 
         << (calc.isPositive(number) ? "Да" : "Нет") << endl;
    cout << endl;
    
    // Глобальные функции
    cout << "=== ГЛОБАЛЬНЫЕ ФУНКЦИИ ===" << endl;
    cout << "Абсолютное значение -42.7: " << absoluteValue(-42.7) << endl;
    cout << "Округление 3.14159 до 2 знаков: " << roundToDecimal(3.14159, 2) << endl;
    cout << endl;
    
    // Константы
    cout << "=== КОНСТАНТЫ ===" << endl;
    cout << "PI = " << PI << endl;
    cout << "E = " << E << endl;
    cout << "Площадь круга (r=5): " << PI * 5 * 5 << endl;
    cout << endl;
    
    // Сброс калькулятора
    calc.reset();
    cout << "После сброса операций: " << calc.getOperationCount() << endl;
    cout << endl;
    
    // Деструктор вызовется автоматически при выходе из main
    return 0;
}
