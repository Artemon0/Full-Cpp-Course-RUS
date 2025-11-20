/*
 * Урок 2: Наследование
 * Тема: Создание иерархии классов
 */

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Базовый класс
class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string и, int в) : name(и), age(в) {}
    
    void showInfo() {
        cout << "Имя: " << name << ", Возраст: " << age << endl;
    }
    
    virtual void makeSound() {
        cout << "Animal издает звук" << endl;
    }
};

// Производный класс - Dog
class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string и, int в, string п) : Animal(и, в), breed(п) {}
    
    void makeSound() override {
        cout << name << " говорит: Гав-гав!" << endl;
    }
    
    void showBreed() {
        cout << "Порода: " << breed << endl;
    }
};

// Производный класс - Cat
class Cat : public Animal {
private:
    bool isDomestic;
    
public:
    Cat(string и, int в, bool д) : Animal(и, в), isDomestic(д) {}
    
    void makeSound() override {
        cout << name << " говорит: Мяу!" << endl;
    }
    
    void showType() {
        if (isDomestic) {
            cout << name << " - isDomestic кошка" << endl;
        } else {
            cout << name << " - дикая кошка" << endl;
        }
    }
};

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=== НАСЛЕДОВАНИЕ ===" << endl;
    
    // Создание объектов
    Dog собака("Рекс", 3, "Немецкая овчарка");
    Cat кошка("Мурка", 2, true);
    
    // Использование методов базового класса
    собака.showInfo();
    собака.showBreed();
    собака.makeSound();
    
    cout << endl;
    
    кошка.showInfo();
    кошка.showType();
    кошка.makeSound();
    
    // Полиморфизм
    cout << "\n=== ПОЛИМОРФИЗМ ===" << endl;
    Animal* животные[2];
    животные[0] = &собака;
    животные[1] = &кошка;
    
    for (int i = 0; i < 2; i++) {
        животные[i]->makeSound();
    }
    
    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте иерархию классов: Транспорт -> Автомобиль, Велосипед
 * 2. Создайте классы: Фигура -> Круг, Треугольник с методом area()
 * 3. Создайте классы: Работник -> Менеджер, Программист с методом зарплата()
 */
