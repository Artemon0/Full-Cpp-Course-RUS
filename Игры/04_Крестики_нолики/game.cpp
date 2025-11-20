/*
 * Игра: Крестики-нолики
 * Описание: Классическая игра для двух игроков
 */

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void showBoard() {
  cout << "\n";
  for (int i = 0; i < 3; i++) {
    cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2]
         << endl;
    if (i < 2)
      cout << "---|---|---" << endl;
  }
  cout << "\n";
}

bool checkWin() {
  // Проверка строк и столбцов
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
      return true;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
      return true;
  }

  // Проверка диагоналей
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return true;
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return true;

  return false;
}

bool checkDraw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
        return false;
      }
    }
  }
  return true;
}

void clearScreen() { system("cls"); }

bool makeMove(int position) {
  int row = (position - 1) / 3;
  int column = (position - 1) % 3;

  if (position < 1 || position > 9) {
    cout << "Неверная позиция! Введите число от 1 до 9." << endl;
    return false;
  }

  if (board[row][column] == 'X' || board[row][column] == 'O') {
    cout << "Эта клетка уже занята!" << endl;
    return false;
  }

  board[row][column] = currentPlayer;
  return true;
}

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  cout << "=== КРЕСТИКИ-НОЛИКИ ===" << endl;
  cout << "Игрок 1: X | Игрок 2: O" << endl;

  while (true) {
    clearScreen();
    showBoard();

    cout << "Ход игрока " << currentPlayer << endl;
    cout << "Выберите позицию (1-9): ";

    int position;
    cin >> position;

    if (!makeMove(position)) {
      continue;
    }

    if (checkWin()) {
      showBoard();
      cout << "🎉 Игрок " << currentPlayer << " победил!" << endl;
      break;
    }

    if (checkDraw()) {
      showBoard();
      cout << "Ничья!" << endl;
      break;
    }

    // Смена игрока
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  return 0;
}
