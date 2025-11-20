/*
 * Урок 2: Наследование
 * Тема: Создание иерархии классов
 */

#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// Базовый класс
class Animal {
protected:
  string name;
  int age;

public:
  Animal(string n, int a) : name(n), age(a) {}

  void showInfo() { cout << "Имя: " << name << ", Возраст: " << age << endl; }

  virtual void makeSound() { cout << "Animal издает звук" << endl; }
};

// Производный класс - Dog
class Dog : public Animal {
private:
  string breed;

public:
  Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

  void makeSound() override { cout << name << " говорит: Гав-гав!" << endl; }

  void showBreed() { cout << "Порода: " << breed << endl; }
};

// Производный класс - Cat
class Cat : public Animal {
private:
  bool isDomestic;

public:
  Cat(string n, int a, bool d) : Animal(n, a), isDomestic(d) {}

  void makeSound() override { cout << name << " говорит: Мяу!" << endl; }

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
  Dog dog("Рекс", 3, "Немецкая овчарка");
  Cat cat("Мурка", 2, true);

  // Использование методов базового класса
  dog.showInfo();
  dog.showBreed();
  dog.makeSound();

  cout << endl;

  cat.showInfo();
  cat.showType();
  cat.makeSound();

  // Полиморфизм
  cout << "\n=== ПОЛИМОРФИЗМ ===" << endl;
  Animal *animals[2];
  animals[0] = &dog;
  animals[1] = &cat;

  for (int i = 0; i < 2; i++) {
    animals[i]->makeSound();
  }

  return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте иерархию классов: Транспорт -> Автомобиль, Велосипед
 * 2. Создайте классы: Фигура -> Круг, Треугольник с методом area()
 * 3. Создайте классы: Работник -> Менеджер, Программист с методом зарплата()
 */
