#include "Calculator.hpp"  // Обратите внимание: .hpp вместо .h
#include <cmath>
#include <iostream>

/*
 * Реализация для .hpp файла
 * Работает точно так же, как и с .h
 */

Calculator::Calculator() {
    lastResult = 0.0;
    operationCount = 0;
    std::cout << "Calculator создан (.hpp версия)" << std::endl;
}

Calculator::~Calculator() {
    std::cout << "Calculator удален. Операций: " << operationCount << std::endl;
}

double Calculator::add(double a, double b) {
    lastResult = a + b;
    operationCount++;
    return lastResult;
}

double Calculator::subtract(double a, double b) {
    lastResult = a - b;
    operationCount++;
    return lastResult;
}

double Calculator::multiply(double a, double b) {
    lastResult = a * b;
    operationCount++;
    return lastResult;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
    lastResult = a / b;
    operationCount++;
    return lastResult;
}

double Calculator::getLastResult() const {
    return lastResult;
}

int Calculator::getOperationCount() const {
    return operationCount;
}
