#include <iostream>
#ifdef _WIN32
#include <windows.h>
// Отключаем макросы min/max из windows.h
#undef min
#undef max
#endif

#include "Array.h"

using namespace std;

/*
 * Пример использования класса Array
 * Демонстрирует продвинутую работу с заголовочными файлами
 *
 * КОМПИЛЯЦИЯ:
 * g++ main_array.cpp Array.cpp -o array_demo
 *
 * ЗАПУСК:
 * ./array_demo (Linux/macOS)
 * array_demo.exe (Windows)
 */

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  cout << "╔════════════════════════════════════════╗" << endl;
  cout << "║   ДЕМОНСТРАЦИЯ КЛАССА ARRAY            ║" << endl;
  cout << "╚════════════════════════════════════════╝" << endl;
  cout << endl;

  // Создание массива
  cout << "=== СОЗДАНИЕ И ЗАПОЛНЕНИЕ ===" << endl;
  Array arr;

  cout << "Добавление элементов: ";
  for (int i = 1; i <= 5; i++) {
    arr.push_back(i * 10);
  }
  cout << arr << endl;
  cout << "Размер: " << arr.getSize() << ", Вместимость: " << arr.getCapacity()
       << endl;
  cout << endl;

  // Доступ к элементам
  cout << "=== ДОСТУП К ЭЛЕМЕНТАМ ===" << endl;
  cout << "Элемент [2]: " << arr[2] << endl;
  arr[2] = 99;
  cout << "После изменения arr[2] = 99: " << arr << endl;
  cout << endl;

  // Вставка и удаление
  cout << "=== ВСТАВКА И УДАЛЕНИЕ ===" << endl;
  arr.insert(2, 777);
  cout << "После insert(2, 777): " << arr << endl;

  arr.remove(3);
  cout << "После remove(3): " << arr << endl;

  arr.pop_back();
  cout << "После pop_back(): " << arr << endl;
  cout << endl;

  // Поиск
  cout << "=== ПОИСК ===" << endl;
  int searchValue = 777;
  int index = arr.find(searchValue);
  if (index != -1) {
    cout << "Значение " << searchValue << " найдено на позиции " << index
         << endl;
  } else {
    cout << "Значение " << searchValue << " не найдено" << endl;
  }
  cout << endl;

  // Статистика
  cout << "=== СТАТИСТИКА ===" << endl;
  cout << "Массив: " << arr << endl;
  cout << "Сумма: " << arr.sum() << endl;
  cout << "Среднее: " << arr.average() << endl;
  cout << "Минимум: " << arr.min() << endl;
  cout << "Максимум: " << arr.max() << endl;
  cout << endl;

  // Сортировка
  cout << "=== СОРТИРОВКА ===" << endl;
  Array arr2;
  arr2.push_back(50);
  arr2.push_back(20);
  arr2.push_back(80);
  arr2.push_back(10);
  arr2.push_back(40);

  cout << "До сортировки: " << arr2 << endl;
  arr2.sort();
  cout << "После сортировки: " << arr2 << endl;
  cout << endl;

  // Реверс
  cout << "=== РЕВЕРС ===" << endl;
  cout << "До реверса: " << arr2 << endl;
  arr2.reverse();
  cout << "После реверса: " << arr2 << endl;
  cout << endl;

  // Копирование
  cout << "=== КОПИРОВАНИЕ ===" << endl;
  Array arr3 = arr2; // Конструктор копирования
  cout << "Оригинал: " << arr2 << endl;
  cout << "Копия: " << arr3 << endl;

  arr3[0] = 999;
  cout << "После изменения копии:" << endl;
  cout << "Оригинал: " << arr2 << endl;
  cout << "Копия: " << arr3 << endl;
  cout << endl;

  // Очистка
  cout << "=== ОЧИСТКА ===" << endl;
  arr.clear();
  cout << "После clear() размер: " << arr.getSize() << endl;
  cout << "Массив пуст? " << (arr.isEmpty() ? "Да" : "Нет") << endl;
  cout << endl;

  return 0;
}
