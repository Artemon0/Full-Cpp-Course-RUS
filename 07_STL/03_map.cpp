/*
 * Урок 3: Map (Словарь)
 * Тема: Ассоциативный контейнер key-value
 */

#include <iostream>
#include <map>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание map
    cout << "=== СОЗДАНИЕ MAP ===" << endl;
    map<string, int> age;
    
    // Добавление элементов
    age["Иван"] = 25;
    age["Мария"] = 30;
    age["Петр"] = 22;
    age.insert({"Анна", 28});
    
    cout << "Размер словаря: " << age.size() << endl;
    
    // Доступ к элементам
    cout << "\n=== ДОСТУП К ЭЛЕМЕНТАМ ===" << endl;
    cout << "Возраст Ивана: " << age["Иван"] << endl;
    cout << "Возраст Марии: " << age.at("Мария") << endl;
    
    // Перебор элементов
    cout << "\n=== ПЕРЕБОР ЭЛЕМЕНТОВ ===" << endl;
    for (const auto& pair : age) {
        cout << pair.first << ": " << pair.second << " лет" << endl;
    }
    
    // Проверка наличия ключа
    cout << "\n=== ПРОВЕРКА НАЛИЧИЯ ===" << endl;
    string name = "Иван";
    if (age.find(name) != age.end()) {
        cout << name << " найден в словаре" << endl;
    }
    
    name = "Сергей";
    if (age.find(name) == age.end()) {
        cout << name << " не найден в словаре" << endl;
    }
    
    // Удаление элемента
    cout << "\n=== УДАЛЕНИЕ ЭЛЕМЕНТА ===" << endl;
    age.erase("Петр");
    cout << "После удаления Петра:" << endl;
    for (const auto& pair : age) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Подсчет частоты слов
    cout << "\n=== ПОДСЧЕТ ЧАСТОТЫ СЛОВ ===" << endl;
    string text[] = {"яблоко", "банан", "яблоко", "груша", "банан", "яблоко"};
    map<string, int> frequency;
    
    for (const string& word : text) {
        frequency[word]++;
    }
    
    cout << "Частота слов:" << endl;
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << " раз" << endl;
    }
    
    // Телефонная книга
    cout << "\n=== ТЕЛЕФОННАЯ КНИГА ===" << endl;
    map<string, string> phones;
    phones["Иван"] = "+7-900-123-45-67";
    phones["Мария"] = "+7-900-234-56-78";
    phones["Петр"] = "+7-900-345-67-89";
    
    cout << "Телефонная книга:" << endl;
    for (const auto& entry : phones) {
        cout << entry.first << ": " << entry.second << endl;
    }
    
    // Очистка map
    age.clear();
    cout << "\nПосле clear размер: " << age.size() << endl;
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для хранения оценок студентов (name -> grade)
 * 2. Создайте словарь для перевода слов (англ -> рус)
 * 3. Создайте программу для подсчета частоты символов в строке
 */
