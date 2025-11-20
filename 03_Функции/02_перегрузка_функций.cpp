/*
 * Урок 8: Перегрузка функций
 * Тема: Функции с одинаковым именем, но разными параметрами
 */

#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <cmath>
using namespace std;

// Перегрузка функции сложения
int add(int a, int b) {
  cout << "Сложение двух целых чисел" << endl;
  return a + b;
}

double add(double a, double b) {
  cout << "Сложение двух дробных чисел" << endl;
  return a + b;
}

int add(int a, int b, int c) {
  cout << "Сложение трех целых чисел" << endl;
  return a + b + c;
}

// Перегрузка функции вывода
void print(int value) { cout << "Целое number: " << value << endl; }

void print(double value) { cout << "Дробное number: " << value << endl; }

void print(string value) { cout << "Строка: " << value << endl; }

void print(char value) { cout << "Символ: " << value << endl; }

// Перегрузка функции площади
double area(double side) {
  cout << "Площадь квадрата" << endl;
  return side * side;
}

double area(double length, double width) {
  cout << "Площадь прямоугольника" << endl;
  return length * width;
}

double area(double radius, bool isCircle) {
  cout << "Площадь круга" << endl;
  return 3.14159 * radius * radius;
}

// Перегрузка функции максимума
int maximum(int a, int b) { return (a > b) ? a : b; }

double maximum(double a, double b) { return (a > b) ? a : b; }

int maximum(int a, int b, int c) {
  int max = a;
  if (b > max)
    max = b;
  if (c > max)
    max = c;
  return max;
}

// Перегрузка функции расстояния
double distance(double x1, double y1, double x2, double y2) {
  cout << "Расстояние между двумя точками на плоскости" << endl;
  double dx = x2 - x1;
  double dy = y2 - y1;
  return sqrt(dx * dx + dy * dy);
}

double distance(double x1, double y1, double z1, double x2, double y2,
                double z2) {
  cout << "Расстояние между двумя точками в пространстве" << endl;
  double dx = x2 - x1;
  double dy = y2 - y1;
  double dz = z2 - z1;
  return sqrt(dx * dx + dy * dy + dz * dz);
}

// Перегрузка функции конвертации
string convert(int number) { return to_string(number); }

int convert(string row) { return stoi(row); }

double convert(string row, bool вДробное) { return stod(row); }

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  // Перегрузка сложения
  cout << "=== ПЕРЕГРУЗКА СЛОЖЕНИЯ ===" << endl;
  cout << "Результат: " << add(5, 3) << endl;
  cout << "Результат: " << add(5.5, 3.2) << endl;
  cout << "Результат: " << add(1, 2, 3) << endl;

  // Перегрузка вывода
  cout << "\n=== ПЕРЕГРУЗКА ВЫВОДА ===" << endl;
  print(42);
  print(3.14);
  print("Привет");
  print('A');

  // Перегрузка площади
  cout << "\n=== ПЕРЕГРУЗКА ПЛОЩАДИ ===" << endl;
  cout << "Результат: " << area(5.0) << endl;
  cout << "Результат: " << area(5.0, 3.0) << endl;
  cout << "Результат: " << area(4.0, true) << endl;

  // Перегрузка максимума
  cout << "\n=== ПЕРЕГРУЗКА МАКСИМУМА ===" << endl;
  cout << "Максимум из 10 и 20: " << maximum(10, 20) << endl;
  cout << "Максимум из 10.5 и 20.3: " << maximum(10.5, 20.3) << endl;
  cout << "Максимум из 5, 15 и 10: " << maximum(5, 15, 10) << endl;

  // Перегрузка расстояния
  cout << "\n=== ПЕРЕГРУЗКА РАССТОЯНИЯ ===" << endl;
  cout << "Результат: " << distance(0.0, 0.0, 3.0, 4.0) << endl;
  cout << "Результат: " << distance(0.0, 0.0, 0.0, 1.0, 1.0, 1.0) << endl;

  // Перегрузка конвертации
  cout << "\n=== ПЕРЕГРУЗКА КОНВЕРТАЦИИ ===" << endl;
  string row = convert(123);
  cout << "Число в строку: " << row << endl;
  int number = convert("456");
  cout << "Строка в number: " << number << endl;
  double decimal = convert("3.14", true);
  cout << "Строка в decimal: " << decimal << endl;

  return 0;
}

/*
 * ПРЕИМУЩЕСТВА ПЕРЕГРУЗКИ:
 * - Один интерфейс для разных типов данных
 * - Код становится более читаемым
 * - Упрощается использование функций
 *
 * ЗАДАНИЕ:
 * 1. Создайте перегруженную функцию для вычисления объема (куб, параллелепипед,
 * цилиндр)
 * 2. Напишите перегруженную функцию для сравнения (два numbers, три numbers,
 * массивы)
 * 3. Создайте перегруженную функцию для форматирования вывода
 */
