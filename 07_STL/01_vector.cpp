/*
 * Урок 1: Vector (Вектор)
 * Тема: Динамический array из STL
 */

#include <algorithm>
#include <iostream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  // Создание вектора
  cout << "=== СОЗДАНИЕ ВЕКТОРА ===" << endl;
  vector<int> numbers;                    // Пустой вектор
  vector<int> numbers2 = {1, 2, 3, 4, 5}; // Инициализация списком
  vector<int> numbers3(5, 10);            // 5 элементов со значением 10

  // Добавление элементов
  cout << "\n=== ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ ===" << endl;
  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_back(30);

  cout << "Размер вектора: " << numbers.size() << endl;

  // Доступ к элементам
  cout << "\n=== ДОСТУП К ЭЛЕМЕНТАМ ===" << endl;
  cout << "Первый элемент: " << numbers[0] << endl;
  cout << "Последний элемент: " << numbers.back() << endl;
  cout << "Элемент по индексу 1: " << numbers.at(1) << endl;

  // Перебор элементов
  cout << "\n=== ПЕРЕБОР ЭЛЕМЕНТОВ ===" << endl;
  cout << "Обычный цикл: ";
  for (size_t i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  cout << "Range-based for: ";
  for (int number : numbers) {
    cout << number << " ";
  }
  cout << endl;

  // Изменение элементов
  cout << "\n=== ИЗМЕНЕНИЕ ЭЛЕМЕНТОВ ===" << endl;
  numbers[0] = 100;
  cout << "После изменения: ";
  for (int number : numbers) {
    cout << number << " ";
  }
  cout << endl;

  // Удаление элементов
  cout << "\n=== УДАЛЕНИЕ ЭЛЕМЕНТОВ ===" << endl;
  numbers.pop_back(); // Удалить последний
  cout << "После pop_back: ";
  for (int number : numbers) {
    cout << number << " ";
  }
  cout << endl;

  // Вставка элемента
  numbers.insert(numbers.begin() + 1, 15); // Вставить 15 на позицию 1
  cout << "После insert: ";
  for (int number : numbers) {
    cout << number << " ";
  }
  cout << endl;

  // Сортировка
  cout << "\n=== СОРТИРОВКА ===" << endl;
  vector<int> unsorted = {5, 2, 8, 1, 9, 3};
  cout << "До сортировки: ";
  for (int number : unsorted) {
    cout << number << " ";
  }
  cout << endl;

  sort(unsorted.begin(), unsorted.end());
  cout << "После сортировки: ";
  for (int number : unsorted) {
    cout << number << " ";
  }
  cout << endl;

  // Поиск элемента
  cout << "\n=== ПОИСК ЭЛЕМЕНТА ===" << endl;
  auto it = find(unsorted.begin(), unsorted.end(), 8);
  if (it != unsorted.end()) {
    cout << "Элемент 8 найден на позиции: " << (it - unsorted.begin()) << endl;
  }

  // Очистка вектора
  numbers.clear();
  cout << "\nПосле clear размер: " << numbers.size() << endl;

  return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для хранения и сортировки оценок студентов
 * 2. Напишите программу для удаления дубликатов из вектора
 * 3. Создайте программу для поиска второго максимального элемента
 */
