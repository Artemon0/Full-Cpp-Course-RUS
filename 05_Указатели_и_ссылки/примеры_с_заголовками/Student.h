#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

/*
 * Заголовочный файл класса Student
 * Демонстрирует разделение объявления и реализации класса
 */

class Student {
private:
    string name;
    int age;
    double gpa;
    
public:
    // Конструктор
    Student(string name, int age, double score);
    
    // Геттеры
    string getName() const;
    int getAge() const;
    double getGPA() const;
    
    // Сеттеры
    void setGPA(double score);
    
    // Методы
    void showInfo() const;
    bool isExcellent() const;
};

#endif // STUDENT_H
