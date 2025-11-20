#include "Calculator.h"
#include <cmath>
#include <iostream>

/*
 * Файл реализации: Calculator.cpp
 * Содержит РЕАЛИЗАЦИЮ методов из Calculator.h
 * 
 * ВАЖНО: Здесь находится логика работы методов
 */

// Конструктор - вызывается при создании объекта
Calculator::Calculator() {
    lastResult = 0.0;
    operationCount = 0;
    std::cout << "Калькулятор создан" << std::endl;
}

// Деструктор - вызывается при удалении объекта
Calculator::~Calculator() {
    std::cout << "Калькулятор удален. Выполнено операций: " << operationCount << std::endl;
}

// Реализация метода сложения
double Calculator::add(double a, double b) {
    lastResult = a + b;
    operationCount++;
    return lastResult;
}

// Реализация метода вычитания
double Calculator::subtract(double a, double b) {
    lastResult = a - b;
    operationCount++;
    return lastResult;
}

// Реализация метода умножения
double Calculator::multiply(double a, double b) {
    lastResult = a * b;
    operationCount++;
    return lastResult;
}

// Реализация метода деления
double Calculator::divide(double a, double b) {
    if (b == 0) {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
    lastResult = a / b;
    operationCount++;
    return lastResult;
}

// Возведение в степень
double Calculator::power(double base, int exponent) {
    lastResult = std::pow(base, exponent);
    operationCount++;
    return lastResult;
}

// Квадратный корень
double Calculator::squareRoot(double number) {
    if (number < 0) {
        std::cout << "Ошибка: корень из отрицательного числа!" << std::endl;
        return 0;
    }
    lastResult = std::sqrt(number);
    operationCount++;
    return lastResult;
}

// Процент от числа
double Calculator::percentage(double number, double percent) {
    lastResult = (number * percent) / 100.0;
    operationCount++;
    return lastResult;
}

// Получить последний результат
double Calculator::getLastResult() const {
    return lastResult;
}

// Получить количество операций
int Calculator::getOperationCount() const {
    return operationCount;
}

// Сброс калькулятора
void Calculator::reset() {
    lastResult = 0.0;
    operationCount = 0;
    std::cout << "Калькулятор сброшен" << std::endl;
}

// Глобальная функция - абсолютное значение
double absoluteValue(double number) {
    return (number < 0) ? -number : number;
}

// Глобальная функция - округление
double roundToDecimal(double number, int decimals) {
    double multiplier = std::pow(10.0, decimals);
    return std::round(number * multiplier) / multiplier;
}
