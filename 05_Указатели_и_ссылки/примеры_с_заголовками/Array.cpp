#include "Array.h"
#include <algorithm>
#include <stdexcept>

// Отключаем макросы min/max из windows.h (если подключен)
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

/*
 * Файл реализации: Array.cpp
 * Реализация динамического массива
 */

// Конструктор по умолчанию
Array::Array() : data(nullptr), size(0), capacity(0) {
}

// Конструктор с размером
Array::Array(int initialSize) : size(initialSize), capacity(initialSize) {
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

// Конструктор копирования
Array::Array(const Array& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// Деструктор
Array::~Array() {
    delete[] data;
}

// Оператор присваивания
Array& Array::operator=(const Array& other) {
    if (this != &other) {  // Защита от самоприсваивания
        delete[] data;
        
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Оператор доступа по индексу (для изменения)
int& Array::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return data[index];
}

// Оператор доступа по индексу (для чтения)
const int& Array::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return data[index];
}

// Увеличение вместимости
void Array::resize(int newCapacity) {
    int* newData = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Добавить элемент в конец
void Array::push_back(int value) {
    if (size >= capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        resize(newCapacity);
    }
    data[size++] = value;
}

// Удалить последний элемент
void Array::pop_back() {
    if (size > 0) {
        size--;
    }
}

// Вставить элемент по индексу
void Array::insert(int index, int value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    
    if (size >= capacity) {
        resize(capacity * 2);
    }
    
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

// Удалить элемент по индексу
void Array::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

// Очистить массив
void Array::clear() {
    size = 0;
}

// Получить размер
int Array::getSize() const {
    return size;
}

// Получить вместимость
int Array::getCapacity() const {
    return capacity;
}

// Проверка на пустоту
bool Array::isEmpty() const {
    return size == 0;
}

// Найти элемент
int Array::find(int value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;  // Не найдено
}

// Сортировка
void Array::sort() {
    std::sort(data, data + size);
}

// Реверс
void Array::reverse() {
    for (int i = 0; i < size / 2; i++) {
        std::swap(data[i], data[size - 1 - i]);
    }
}

// Сумма элементов
int Array::sum() const {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += data[i];
    }
    return total;
}

// Среднее значение
double Array::average() const {
    if (size == 0) return 0.0;
    return static_cast<double>(sum()) / size;
}

// Минимум
int Array::min() const {
    if (size == 0) {
        throw std::runtime_error("Массив пуст");
    }
    int minVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < minVal) {
            minVal = data[i];
        }
    }
    return minVal;
}

// Максимум
int Array::max() const {
    if (size == 0) {
        throw std::runtime_error("Массив пуст");
    }
    int maxVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

// Вывод массива
void Array::print() const {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << data[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]";
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Array& arr) {
    arr.print();
    return os;
}
