#ifndef CALCULATOR_H
#define CALCULATOR_H

/*
 * Заголовочный файл: Calculator.h
 * Демонстрирует создание класса-калькулятора
 * 
 * ВАЖНО: Заголовочный файл содержит только ОБЪЯВЛЕНИЯ
 * - Объявления классов
 * - Объявления методов
 * - Объявления переменных (extern)
 * - Inline функции (небольшие)
 */

class Calculator {
private:
    // Приватные поля - доступны только внутри класса
    double lastResult;
    int operationCount;
    
public:
    // Конструктор - инициализирует объект
    Calculator();
    
    // Деструктор - вызывается при удалении объекта
    ~Calculator();
    
    // Основные операции
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    // Дополнительные операции
    double power(double base, int exponent);
    double squareRoot(double number);
    double percentage(double number, double percent);
    
    // Геттеры - получение значений приватных полей
    double getLastResult() const;  // const - метод не изменяет объект
    int getOperationCount() const;
    
    // Сброс калькулятора
    void reset();
    
    // Inline функция - определена прямо в .h файле
    // Используется для маленьких функций
    inline bool isPositive(double number) const {
        return number > 0;
    }
};

// Глобальные функции (не методы класса)
double absoluteValue(double number);
double roundToDecimal(double number, int decimals);

// Константы
const double PI = 3.14159265359;
const double E = 2.71828182846;

#endif // CALCULATOR_H
