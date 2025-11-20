/*
 * Урок 1: Чтение и entry файлов
 * Тема: Работа с текстовыми файлами
 */

#include <fstream>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  // Запись в файл
  cout << "=== ЗАПИСЬ В ФАЙЛ ===" << endl;
  ofstream outputFile("данные.txt");

  if (outputFile.is_open()) {
    outputFile << "Привет, мир!" << endl;
    outputFile << "Это вторая row" << endl;
    outputFile << "Число: " << 42 << endl;
    outputFile.close();
    cout << "Данные записаны в файл данные.txt" << endl;
  } else {
    cout << "Ошибка открытия файла для записи!" << endl;
  }

  // Чтение из файла
  cout << "\n=== ЧТЕНИЕ ИЗ ФАЙЛА ===" << endl;
  ifstream inputFile("данные.txt");

  if (inputFile.is_open()) {
    string row;
    cout << "Содержимое файла:" << endl;
    while (getline(inputFile, row)) {
      cout << row << endl;
    }
    inputFile.close();
  } else {
    cout << "Ошибка открытия файла для чтения!" << endl;
  }

  // Добавление в конец файла
  cout << "\n=== ДОБАВЛЕНИЕ В ФАЙЛ ===" << endl;
  ofstream appendFile("данные.txt", ios::app);

  if (appendFile.is_open()) {
    appendFile << "Добавленная row" << endl;
    appendFile.close();
    cout << "Строка добавлена в файл" << endl;
  }

  // Чтение чисел из файла
  cout << "\n=== РАБОТА С ЧИСЛАМИ ===" << endl;
  ofstream numbersFile("numbers.txt");
  numbersFile << "10 20 30 40 50";
  numbersFile.close();

  ifstream readNumbers("numbers.txt");
  int number;
  int sum = 0;

  cout << "Числа из файла: ";
  while (readNumbers >> number) {
    cout << number << " ";
    sum += number;
  }
  cout << "\nСумма: " << sum << endl;
  readNumbers.close();

  return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для копирования содержимого одного файла в другой
 * 2. Напишите программу для подсчета количества строк в файле
 * 3. Создайте программу для поиска words в файле
 */
