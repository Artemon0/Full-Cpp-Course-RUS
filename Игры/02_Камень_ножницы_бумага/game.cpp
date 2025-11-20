/*
 * Игра: Камень, ножницы, бумага
 * Описание: Классическая игра против компьютера
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

string getChoice(int number) {
  if (number == 1)
    return "Камень";
  if (number == 2)
    return "Ножницы";
  return "Бумага";
}

int determineWinner(int player, int computer) {
  if (player == computer)
    return 0; // Ничья

  if ((player == 1 && computer == 2) || // Камень бьет ножницы
      (player == 2 && computer == 3) || // Ножницы бьют бумагу
      (player == 3 && computer == 1)) {
    // Бумага бьет камень
    return 1; // Игрок победил
  }

  return 2; // Компьютер победил
}

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  srand(time(0));

  cout << "=== КАМЕНЬ, НОЖНИЦЫ, БУМАГА ===" << endl;

  int playerWins = 0;
  int computerWins = 0;
  int draws = 0;

  while (true) {
    cout << "\n1. Камень" << endl;
    cout << "2. Ножницы" << endl;
    cout << "3. Бумага" << endl;
    cout << "0. Выход" << endl;
    cout << "Ваш выбор: ";

    int playerChoice;
    cin >> playerChoice;

    if (playerChoice == 0) {
      break;
    }

    if (playerChoice < 1 || playerChoice > 3) {
      cout << "Неверный выбор! Попробуйте снова." << endl;
      continue;
    }

    int computerChoice = rand() % 3 + 1;

    cout << "\nВы выбрали: " << getChoice(playerChoice) << endl;
    cout << "Компьютер выбрал: " << getChoice(computerChoice) << endl;

    int result = determineWinner(playerChoice, computerChoice);

    if (result == 0) {
      cout << "Ничья!" << endl;
      draws++;
    } else if (result == 1) {
      cout << "🎉 Вы победили!" << endl;
      playerWins++;
    } else {
      cout << "😞 Компьютер победил!" << endl;
      computerWins++;
    }

    cout << "\n--- СЧЕТ ---" << endl;
    cout << "Вы: " << playerWins << " | Компьютер: " << computerWins
         << " | Ничьи: " << draws << endl;
  }

  cout << "\n=== ФИНАЛЬНЫЙ СЧЕТ ===" << endl;
  cout << "Ваши победы: " << playerWins << endl;
  cout << "Победы компьютера: " << computerWins << endl;
  cout << "Ничьи: " << draws << endl;
  cout << "Спасибо за игру!" << endl;

  return 0;
}
