/*
 * Урок 2: Переменные и типы данных
 * Тема: Объявление и использование переменных
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
  // Целые числа
  int age = 25;
  int year = 2025;

  // Числа с плавающей точкой
  float height = 175.5f;
  double weight = 70.3;

  // Символы
  char grade = 'A';

  // Логические значения
  bool isStudent = true;

  // Строки
  string name = "Иван";

  // Вывод переменных
  cout << "=== Информация о человеке ===" << endl;
  cout << "Имя: " << name << endl;
  cout << "Возраст: " << age << " лет" << endl;
  cout << "Рост: " << height << " см" << endl;
  cout << "Вес: " << weight << " кг" << endl;
  cout << "Оценка: " << grade << endl;
  cout << "Студент: " << (isStudent ? "Да" : "Нет") << endl;

  // Арифметические операции
  int birthYear = year - age;
  cout << "\nГод рождения: " << birthYear << endl;

  // Ввод данных от пользователя
  cout << "\n=== Введите свои данные ===" << endl;
  cout << "Ваше имя: ";
  cin >> name;
  cout << "Ваш возраст: ";
  cin >> age;

  cout << "\nПривет, " << name << "! Тебе " << age << " лет." << endl;

  return 0;
}

/*
 * ТИПЫ ДАННЫХ:
 *
 * int - целые числа (-2147483648 до 2147483647)
 * float - числа с плавающей точкой (7 знаков точности)
 * double - числа с двойной точностью (15 знаков)
 * char - один символ ('A', 'b', '1')
 * bool - логическое значение (true/false)
 * string - строка текста
 *
 * ЗАДАНИЕ:
 * 1. Создайте переменные для описания автомобиля (марка, год, цена)
 * 2. Выведите информацию об автомобиле
 * 3. Попросите пользователя ввести данные о его автомобиле
 */

class Car {

  static int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    string name;
    int age;
    float price;

    cout << "name: ";
    cin >> name;
    cout << "age: ";
    cin >> age;
    cout << "price: ";
    cin >> price;

    cout << "name: " << name + "age: " << age << "price: " << price;

    return 0;
  }
};