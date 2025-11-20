/*
 * Урок 3: Заголовочные файлы (.h)
 * Тема: Разделение объявления и реализации
 *
 * ВАЖНО: Этот файл демонстрирует концепцию.
 * Смотрите примеры в папке примеры_с_заголовками/
 */

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

/*
 * ЧТО ТАКОЕ ЗАГОЛОВОЧНЫЕ ФАЙЛЫ?
 *
 * .h (header) файлы содержат:
 * - Объявления функций
 * - Объявления классов
 * - Константы
 * - Макросы
 *
 * .cpp файлы содержат:
 * - Реализацию функций
 * - Реализацию методов классов
 *
 * ЗАЧЕМ ЭТО НУЖНО?
 * 1. Разделение интерфейса и реализации
 * 2. Возможность использовать код в разных файлах
 * 3. Ускорение компиляции больших проектов
 * 4. Улучшение читаемости кода
 */

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  cout << "=== ЗАГОЛОВОЧНЫЕ ФАЙЛЫ ===" << endl;
  cout << "\nСтруктура проекта с заголовочными файлами:\n" << endl;

  cout << "math.h       - объявления функций" << endl;
  cout << "math.cpp     - реализация функций" << endl;
  cout << "main.cpp     - использование функций" << endl;

  cout << "\n=== ПРИМЕР СТРУКТУРЫ ===" << endl;
  cout << "\n// math.h" << endl;
  cout << "#ifndef MATH_H" << endl;
  cout << "#define MATH_H" << endl;
  cout << "" << endl;
  cout << "int add(int a, int b);" << endl;
  cout << "int multiply(int a, int b);" << endl;
  cout << "" << endl;
  cout << "#endif" << endl;

  cout << "\n// math.cpp" << endl;
  cout << "#include \"math.h\"" << endl;
  cout << "" << endl;
  cout << "int add(int a, int b) {" << endl;
  cout << "    return a + b;" << endl;
  cout << "}" << endl;

  cout << "\n// main.cpp" << endl;
  cout << "#include \"math.h\"" << endl;
  cout << "int result = add(5, 3);" << endl;

  cout << "\n=== КОМПИЛЯЦИЯ ===" << endl;
  cout << "g++ main.cpp math.cpp -o program" << endl;

  cout << "\nСмотрите практические примеры в папке:" << endl;
  cout << "05_Указатели_и_ссылки/примеры_с_заголовками/" << endl;

  return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Изучите примеры в папке примеры_с_заголовками/
 * 2. Создайте свой модуль с .h и .cpp файлами
 * 3. Попробуйте скомпилировать многофайловый проект
 */
