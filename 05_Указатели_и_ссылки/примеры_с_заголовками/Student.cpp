#include "Student.h"
#include <iostream>
using namespace std;

/*
 * Файл реализации класса Student
 */

// Конструктор
Student::Student(string name, int age, double score) 
    : name(name), age(age), gpa(score) {}

// Геттеры
string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

double Student::getGPA() const {
    return gpa;
}

// Сеттеры
void Student::setGPA(double score) {
    if (score >= 0 && score <= 5) {
        gpa = score;
    }
}

// Методы
void Student::showInfo() const {
    cout << "Студент: " << name << endl;
    cout << "Возраст: " << age << " лет" << endl;
    cout << "Средний балл: " << gpa << endl;
    if (isExcellent()) {
        cout << "Статус: Отличник! 🌟" << endl;
    }
}

bool Student::isExcellent() const {
    return gpa >= 4.5;
}
