/*
 * Игра: Угадай число
 * Описание: Компьютер загадывает число, игрок должен его угадать
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки UTF-8 для корректного отображения русского текста
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Инициализация генератора случайных чисел
    srand(time(0));
    
    cout << "=== ИГРА: УГАДАЙ ЧИСЛО ===" << endl;
    cout << "Я загадал число от 1 до 100. Попробуй угадать!" << endl;
    
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    do {
        cout << "\nВведите ваше число: ";
        cin >> guess;
        attempts++;
        
        if (guess < secretNumber) {
            cout << "Слишком мало! Попробуй больше." << endl;
        } else if (guess > secretNumber) {
            cout << "Слишком много! Попробуй меньше." << endl;
        } else {
            cout << "\n🎉 Поздравляю! Вы угадали число " << secretNumber << "!" << endl;
            cout << "Количество попыток: " << attempts << endl;
            
            // Оценка результата
            if (attempts <= 5) {
                cout << "Отличный результат!" << endl;
            } else if (attempts <= 10) {
                cout << "Хороший результат!" << endl;
            } else {
                cout << "Можно лучше!" << endl;
            }
        }
    } while (guess != secretNumber);
    
    return 0;
}
