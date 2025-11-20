/*
 * Урок 2: Ссылки
 * Тема: Работа со ссылками и их отличия от указателей
 */

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// Функция с передачей по значению
void changeByValue(int x) {
  x = 100;
  cout << "Внутри функции (по значению): " << x << endl;
}

// Функция с передачей по ссылке
void changeByReference(int &x) {
  x = 100;
  cout << "Внутри функции (по ссылке): " << x << endl;
}

// Функция обмена значений
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  // Основы ссылок
  cout << "=== ОСНОВЫ ССЫЛОК ===" << endl;
  int number = 42;
  int &reference = number; // Ссылка - это псевдоним переменной

  cout << "Значение переменной: " << number << endl;
  cout << "Значение ссылки: " << reference << endl;

  reference = 100; // Изменение через ссылку
  cout << "После изменения через ссылку: " << number << endl;

  // Передача по значению vs по ссылке
  cout << "\n=== ПЕРЕДАЧА ПАРАМЕТРОВ ===" << endl;
  int a = 10;
  cout << "До вызова: a = " << a << endl;
  changeByValue(a);
  cout << "После вызова (по значению): a = " << a << endl;

  changeByReference(a);
  cout << "После вызова (по ссылке): a = " << a << endl;

  // Обмен значений
  cout << "\n=== ОБМЕН ЗНАЧЕНИЙ ===" << endl;
  int x = 5, y = 10;
  cout << "До обмена: x = " << x << ", y = " << y << endl;
  swap(x, y);
  cout << "После обмена: x = " << x << ", y = " << y << endl;

  // Константные ссылки
  cout << "\n=== КОНСТАНТНЫЕ ССЫЛКИ ===" << endl;
  const int &constRef = number;
  cout << "Константная reference: " << constRef << endl;
  // constRef = 200;  // ОШИБКА: нельзя изменить через const ссылку

  return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте функцию для нахождения минимума и максимума через ссылки
 * 2. Напишите функцию сортировки трех чисел по возрастанию через ссылки
 * 3. Реализуйте функцию для вычисления площади и периметра прямоугольника
 */
