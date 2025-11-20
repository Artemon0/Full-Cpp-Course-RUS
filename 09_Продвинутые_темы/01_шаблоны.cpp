/*
 * Урок 1: Шаблоны (Templates)
 * Тема: Обобщенное программирование
 */

#include <iostream>
#include <windows.h>
using namespace std;

// Шаблон функции
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Шаблон функции с несколькими параметрами
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Шаблон класса
template <typename T>
class Pair {
private:
    T first;
    T second;
    
public:
    Pair(T п, T в) : first(п), second(в) {}
    
    T getFirst() { return first; }
    T getSecond() { return second; }
    
    void show() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

// Шаблон класса с двумя типами
template <typename T1, typename T2>
class KeyValue {
private:
    T1 key;
    T2 value;
    
public:
    KeyValue(T1 к, T2 з) : key(к), value(з) {}
    
    void show() {
        cout << key << " => " << value << endl;
    }
};

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Использование шаблона функции
    cout << "=== ШАБЛОНЫ ФУНКЦИЙ ===" << endl;
    cout << "Максимум (5, 10): " << maximum(5, 10) << endl;
    cout << "Максимум (3.14, 2.71): " << maximum(3.14, 2.71) << endl;
    cout << "Максимум ('a', 'z'): " << maximum('a', 'z') << endl;
    
    // Обмен значений
    cout << "\n=== ОБМЕН ЗНАЧЕНИЙ ===" << endl;
    int x = 100, y = 200;
    cout << "До обмена: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "После обмена: x = " << x << ", y = " << y << endl;
    
    // Использование шаблона класса
    cout << "\n=== ШАБЛОНЫ КЛАССОВ ===" << endl;
    Pair<int> numberPair(10, 20);
    cout << "Pair чисел: ";
    numberPair.show();
    
    Pair<string> stringPair("Привет", "Мир");
    cout << "Pair строк: ";
    stringPair.show();
    
    // Класс с двумя типами
    cout << "\n=== КЛАСС С ДВУМЯ ТИПАМИ ===" << endl;
    KeyValue<string, int> age("Иван", 25);
    age.show();
    
    KeyValue<int, string> isStudent(1, "Мария");
    isStudent.show();
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте шаблон функции для поиска минимума в массиве
 * 2. Создайте шаблонный класс Стек с методами push, pop, top
 * 3. Создайте шаблон функции для сортировки массива
 */
