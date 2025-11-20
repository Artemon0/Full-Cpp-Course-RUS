/*
 * Урок 3: Операторы
 * Тема: Арифметические, логические и операторы сравнения
 */

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  // Арифметические операторы
  cout << "=== АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ ===" << endl;
  int a = 10, b = 3;

  cout << "a = " << a << ", b = " << b << endl;
  cout << "Сложение: a + b = " << (a + b) << endl;
  cout << "Вычитание: a - b = " << (a - b) << endl;
  cout << "Умножение: a * b = " << (a * b) << endl;
  cout << "Деление: a / b = " << (a / b) << endl;
  cout << "Остаток: a % b = " << (a % b) << endl;

  // Операторы инкремента и декремента
  cout << "\n=== ИНКРЕМЕНТ И ДЕКРЕМЕНТ ===" << endl;
  int x = 5;
  cout << "x = " << x << endl;
  cout << "x++ = " << x++ << " (после: x = " << x << ")" << endl;
  cout << "++x = " << ++x << " (после: x = " << x << ")" << endl;
  cout << "x-- = " << x-- << " (после: x = " << x << ")" << endl;
  cout << "--x = " << --x << " (после: x = " << x << ")" << endl;

  // Операторы сравнения
  cout << "\n=== ОПЕРАТОРЫ СРАВНЕНИЯ ===" << endl;
  cout << "10 == 10: " << (10 == 10) << endl;
  cout << "10 != 5: " << (10 != 5) << endl;
  cout << "10 > 5: " << (10 > 5) << endl;
  cout << "10 < 5: " << (10 < 5) << endl;
  cout << "10 >= 10: " << (10 >= 10) << endl;
  cout << "10 <= 5: " << (10 <= 5) << endl;

  // Логические операторы
  cout << "\n=== ЛОГИЧЕСКИЕ ОПЕРАТОРЫ ===" << endl;
  bool p = true, q = false;
  cout << "p = " << p << ", q = " << q << endl;
  cout << "p && q (И): " << (p && q) << endl;
  cout << "p || q (ИЛИ): " << (p || q) << endl;
  cout << "!p (НЕ): " << (!p) << endl;

  // Составные операторы присваивания
  cout << "\n=== СОСТАВНЫЕ ОПЕРАТОРЫ ===" << endl;
  int num = 10;
  cout << "num = " << num << endl;
  num += 5; // num = num + 5
  cout << "num += 5: " << num << endl;
  num -= 3; // num = num - 3
  cout << "num -= 3: " << num << endl;
  num *= 2; // num = num * 2
  cout << "num *= 2: " << num << endl;
  num /= 4; // num = num / 4
  cout << "num /= 4: " << num << endl;

  // Практический пример: калькулятор
  cout << "\n=== ПРОСТОЙ КАЛЬКУЛЯТОР ===" << endl;
  double num1, num2;
  cout << "Введите первое number: ";
  cin >> num1;
  cout << "Введите второе number: ";
  cin >> num2;

  cout << "\nРезультаты:" << endl;
  cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
  cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
  cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
  if (num2 != 0) {
    cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
  } else {
    cout << "Деление на ноль невозможно!" << endl;
  }

  return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для конвертации температуры (Цельсий в Фаренгейт)
 * 2. Напишите программу для расчета площади и периметра прямоугольника
 * 3. Создайте калькулятор для расчета ИМТ (индекс массы тела)
 */
