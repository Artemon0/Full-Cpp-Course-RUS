#include <iostream>
#include "Student.h"
#include <windows.h>

using namespace std;

/*
 * Пример использования класса Student
 * 
 * КОМПИЛЯЦИЯ:
 * g++ main_student.cpp Student.cpp -o students
 * 
 * ЗАПУСК:
 * ./students (Linux/Mac)
 * students.exe (Windows)
 */

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=== СИСТЕМА УЧЕТА СТУДЕНТОВ ===" << endl;
    
    // Создание студентов
    Student student1("Иван Петров", 20, 4.8);
    Student student2("Мария Сидорова", 19, 4.2);
    Student student3("Алексей Иванов", 21, 3.9);
    
    // Вывод информации
    cout << "\n--- Студент 1 ---" << endl;
    student1.showInfo();
    
    cout << "\n--- Студент 2 ---" << endl;
    student2.showInfo();
    
    cout << "\n--- Студент 3 ---" << endl;
    student3.showInfo();
    
    // Изменение балла
    cout << "\n=== ОБНОВЛЕНИЕ ДАННЫХ ===" << endl;
    student3.setGPA(4.6);
    cout << "Балл студента " << student3.getName() 
         << " обновлен до " << student3.getGPA() << endl;
    student3.showInfo();
    
    return 0;
}
