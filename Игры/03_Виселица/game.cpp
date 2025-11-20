/*
 * Игра: Виселица
 * Описание: Угадай слово по буквам
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

void showHangman(int errors) {
  cout << "\n";
  if (errors >= 1)
    cout << "  O  " << endl;
  if (errors >= 2)
    cout << " /";
  if (errors >= 3)
    cout << "|";
  if (errors >= 4)
    cout << "\\" << endl;
  if (errors >= 5)
    cout << " /";
  if (errors >= 6)
    cout << " \\" << endl;
  cout << "\n";
}

int main() {
  // Установка кодировки UTF-8 для корректного отображения русского текста
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  vector<string> words = {"программирование", "компьютер", "алгоритм",
                          "функция", "переменная"};

  cout << "=== ИГРА: ВИСЕЛИЦА ===" << endl;

  // Выбор случайного слова
  srand(time(nullptr));
  string secretWord = words[rand() % words.size()];
  string guessedWord(secretWord.length(), '_');

  vector<char> usedLetters;
  int errors = 0;
  const int maxErrors = 6;

  while (errors < maxErrors && guessedWord != secretWord) {
    showHangman(errors);

    cout << "Слово: ";
    for (char c : guessedWord) {
      cout << c << " ";
    }
    cout << endl;

    cout << "Использованные буквы: ";
    for (char c : usedLetters) {
      cout << c << " ";
    }
    cout << endl;

    cout << "Ошибок: " << errors << "/" << maxErrors << endl;

    cout << "\nВведите букву: ";
    char letter;
    cin >> letter;
    letter = tolower(letter);

    // Проверка, использовалась ли буква
    if (find(usedLetters.begin(), usedLetters.end(), letter) !=
        usedLetters.end()) {
      cout << "Вы уже использовали эту букву!" << endl;
      continue;
    }

    usedLetters.push_back(letter);

    // Проверка наличия буквы в слове
    bool found = false;
    for (size_t i = 0; i < secretWord.length(); i++) {
      if (secretWord[i] == letter) {
        guessedWord[i] = letter;
        found = true;
      }
    }

    if (found) {
      cout << "✓ Правильно!" << endl;
    } else {
      cout << "✗ Неправильно!" << endl;
      errors++;
    }
  }

  // Результат игры
  cout << "\n";
  if (guessedWord == secretWord) {
    cout << "🎉 Поздравляю! Вы угадали слово: " << secretWord << endl;
  } else {
    showHangman(errors);
    cout << "😞 Вы проиграли! Загаданное слово: " << secretWord << endl;
  }

  return 0;
}
