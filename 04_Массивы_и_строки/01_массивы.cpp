/*
 * Урок 9: Массивы
 * Тема: Одномерные и многомерные массивы
 */

#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Объявление и инициализация массива
    cout << "=== ОСНОВЫ МАССИВОВ ===" << endl;
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "Элементы массива:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }

    // Ввод элементов массива
    cout << "\n=== ВВОД МАССИВА ===" << endl;
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int *array = new int[size];
    cout << "Введите " << size << " чисел:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Элемент " << i << ": ";
        cin >> array[i];
    }

    // Вывод массива
    cout << "\nВаш массив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Сумма элементов
    cout << "\n=== СУММА ЭЛЕМЕНТОВ ===" << endl;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    cout << "Сумма: " << sum << endl;
    cout << "Среднее: " << (double) sum / size << endl;

    // Поиск максимума и минимума
    cout << "\n=== МАКСИМУМ И МИНИМУМ ===" << endl;
    int max = array[0];
    int min = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }

    cout << "Максимум: " << max << endl;
    cout << "Минимум: " << min << endl;

    // Реверс массива
    cout << "\n=== РЕВЕРС МАССИВА ===" << endl;
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }

    cout << "Перевернутый массив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    // Двумерный массив (матрица)
    cout << "\n=== ДВУМЕРНЫЙ МАССИВ ===" << endl;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Матрица 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Сумма диагоналей
    int mainDiagSum = 0;
    int secDiagSum = 0;
    for (int i = 0; i < 3; i++) {
        mainDiagSum += matrix[i][i];
        secDiagSum += matrix[i][2 - i];
    }
    cout << "Сумма главной диагонали: " << mainDiagSum << endl;
    cout << "Сумма побочной диагонали: " << secDiagSum << endl;

    // Поиск элемента
    cout << "\n=== ПОИСК ЭЛЕМЕНТА ===" << endl;
    int grades[] = {85, 92, 78, 95, 88};
    int searchValue;
    cout << "Оценки: ";
    for (int i = 0; i < 5; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;

    cout << "Введите оценку для поиска: ";
    cin >> searchValue;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (grades[i] == searchValue) {
            cout << "Оценка найдена на позиции " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Оценка не найдена" << endl;
    }

    // Сортировка массива
    cout << "\n=== СОРТИРОВКА МАССИВА ===" << endl;
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    cout << "До сортировки: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    sort(data, data + n);

    cout << "После сортировки: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * ЗАДАНИЕ:
 * 1. Создайте программу для подсчета четных и нечетных чисел в массиве
 * 2. Напишите программу для удаления дубликатов из массива
 * 3. Создайте программу для транспонирования матрицы
 * 4. Реализуйте линейный и бинарный поиск
 */
