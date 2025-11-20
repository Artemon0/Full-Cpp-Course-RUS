#include <iostream>
#include <windows.h>
#include "Calculator.hpp"  // Используем .hpp

using namespace std;

/*
 * Пример использования .hpp файла
 * 
 * КОМПИЛЯЦИЯ (точно так же, как с .h):
 * g++ main.cpp Calculator.cpp -o calculator_hpp
 * 
 * ЗАПУСК:
 * ./calculator_hpp (Linux/macOS)
 * calculator_hpp.exe (Windows)
 */

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║   ПРИМЕР С .HPP РАСШИРЕНИЕМ            ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << endl;
    
    Calculator calc;
    cout << endl;
    
    cout << "=== ДЕМОНСТРАЦИЯ ===" << endl;
    cout << "10 + 5 = " << calc.add(10, 5) << endl;
    cout << "10 - 5 = " << calc.subtract(10, 5) << endl;
    cout << "10 * 5 = " << calc.multiply(10, 5) << endl;
    cout << "10 / 5 = " << calc.divide(10, 5) << endl;
    cout << endl;
    
    cout << "Последний результат: " << calc.getLastResult() << endl;
    cout << "Выполнено операций: " << calc.getOperationCount() << endl;
    cout << endl;
    
    cout << "Константа PI: " << PI << endl;
    cout << endl;
    
    cout << "✅ Работает точно так же, как с .h файлами!" << endl;
    cout << "   Разница только в расширении файла." << endl;
    cout << endl;
    
    return 0;
}
