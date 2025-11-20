#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

/*
 * Пример с расширением .hpp
 * Функционально идентичен Calculator.h
 * 
 * Разница только в расширении файла!
 */

class Calculator {
private:
    double lastResult;
    int operationCount;
    
public:
    Calculator();
    ~Calculator();
    
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    double getLastResult() const;
    int getOperationCount() const;
    
    inline bool isPositive(double number) const {
        return number > 0;
    }
};

const double PI = 3.14159265359;

#endif // CALCULATOR_HPP
