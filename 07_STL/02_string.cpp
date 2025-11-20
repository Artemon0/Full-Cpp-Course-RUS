/*
 * Урок 2: String (Строки)
 * Тема: Работа со строками в STL
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание строк
    cout << "=== СОЗДАНИЕ СТРОК ===" << endl;
    string str1 = "Привет";
    string str2("Мир");
    string str3(5, 'A');  // "AAAAA"
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    
    // Конкатенация строк
    cout << "\n=== КОНКАТЕНАЦИЯ ===" << endl;
    string fullString = str1 + ", " + str2 + "!";
    cout << fullString << endl;
    
    // Длина строки
    cout << "\n=== ДЛИНА СТРОКИ ===" << endl;
    cout << "Длина: " << fullString.length() << endl;
    cout << "Размер: " << fullString.size() << endl;
    
    // Доступ к символам
    cout << "\n=== ДОСТУП К СИМВОЛАМ ===" << endl;
    cout << "Первый символ: " << fullString[0] << endl;
    cout << "Последний символ: " << fullString.back() << endl;
    
    // Подстрока
    cout << "\n=== ПОДСТРОКА ===" << endl;
    string substring = fullString.substr(0, 6);  // С позиции 0, length 6
    cout << "Подстрока: " << substring << endl;
    
    // Поиск в строке
    cout << "\n=== ПОИСК ===" << endl;
    size_t position = fullString.find("Мир");
    if (position != string::npos) {
        cout << "\"Мир\" найдено на позиции: " << position << endl;
    }
    
    // Замена
    cout << "\n=== ЗАМЕНА ===" << endl;
    string text = "Я люблю C++";
    text.replace(8, 3, "Python");  // Заменить 3 символа с позиции 8
    cout << "После замены: " << text << endl;
    
    // Вставка и удаление
    cout << "\n=== ВСТАВКА И УДАЛЕНИЕ ===" << endl;
    string row = "Hello World";
    row.insert(5, " Beautiful");
    cout << "После вставки: " << row << endl;
    
    row.erase(5, 10);  // Удалить 10 символов с позиции 5
    cout << "После удаления: " << row << endl;
    
    // Сравнение строк
    cout << "\n=== СРАВНЕНИЕ ===" << endl;
    string s1 = "apple";
    string s2 = "banana";
    if (s1 < s2) {
        cout << s1 << " идет раньше " << s2 << " в алфавите" << endl;
    }
    
    // Преобразование регистра
    cout << "\n=== ПРЕОБРАЗОВАНИЕ РЕГИСТРА ===" << endl;
    string text2 = "Hello World";
    transform(text2.begin(), text2.end(), text2.begin(), ::toupper);
    cout << "Верхний регистр: " << text2 << endl;
    
    transform(text2.begin(), text2.end(), text2.begin(), ::tolower);
    cout << "Нижний регистр: " << text2 << endl;
    
    // Проверка на пустоту
    cout << "\n=== ПРОВЕРКА НА ПУСТОТУ ===" << endl;
    string empty = "";
    cout << "Строка empty? " << (empty.empty() ? "Да" : "Нет") << endl;
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для подсчета количества слов в строке
 * 2. Напишите программу для проверки, является ли row палиндромом
 * 3. Создайте программу для удаления всех пробелов из строки
 */
