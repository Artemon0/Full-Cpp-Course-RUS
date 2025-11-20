@echo off
chcp 65001 > nul
:menu
cls

echo.
echo ╔════════════════════════════════════════╗
echo ║   КУРС C++ - ГЛАВНОЕ МЕНЮ              ║
echo ╚════════════════════════════════════════╝
echo.
echo Выберите действие:
echo.
echo ┌────────────────────────────────────────┐
echo │  КОМПИЛЯЦИЯ И ЗАПУСК                   │
echo ├────────────────────────────────────────┤
echo │  1. Компилировать любой урок           │
echo │  2. Компилировать игру                 │
echo └────────────────────────────────────────┘
echo.
echo ┌────────────────────────────────────────┐
echo │  ПРОВЕРКА И НАСТРОЙКА                  │
echo ├────────────────────────────────────────┤
echo │  3. Проверить компилятор (g++)         │
echo │  4. Обновить PATH                      │
echo │  5. Тест компиляции                    │
echo │  6. Тест кодировки UTF-8               │
echo └────────────────────────────────────────┘
echo.
echo ┌────────────────────────────────────────┐
echo │  ПРИМЕРЫ И ДЕМОНСТРАЦИИ                │
echo ├────────────────────────────────────────┤
echo │  7. Демо Include Guards                │
echo │  8. Компиляция всех примеров .h        │
echo │  9. Открыть CMD в этой папке           │
echo └────────────────────────────────────────┘
echo.
echo ┌────────────────────────────────────────┐
echo │  ДОКУМЕНТАЦИЯ                          │
echo ├────────────────────────────────────────┤
echo │  D. Открыть README.md                  │
echo │  H. Открыть КАК_КОМПИЛИРОВАТЬ.md       │
echo │  0. Выход                              │
echo └────────────────────────────────────────┘
echo.

choice /c 123456789DH0 /n /m "Ваш выбор: "

if errorlevel 12 exit /b
if errorlevel 11 goto doc2
if errorlevel 10 goto doc1
if errorlevel 9 goto opencmd
if errorlevel 8 goto compile_examples
if errorlevel 7 goto demo_guards
if errorlevel 6 goto test_encoding
if errorlevel 5 goto test_compile
if errorlevel 4 goto update_path
if errorlevel 3 goto check_gcc
if errorlevel 2 goto compile_game
if errorlevel 1 goto compile_lesson

:compile_lesson
cls
call КОМПИЛИРОВАТЬ_УРОК.bat
goto menu

:compile_game
cls
cd Игры
echo.
echo Выберите игру:
echo  1. Угадай число
echo  2. Камень, ножницы, бумага
echo  3. Виселица
echo  4. Крестики-нолики
echo.
choice /c 1234 /n /m "Ваш выбор: "
if errorlevel 4 (
    cd 04_Крестики_нолики
    g++ game.cpp -o tictactoe.exe
    if not errorlevel 1 tictactoe.exe
)
if errorlevel 3 (
    cd 03_Виселица
    g++ game.cpp -o hangman.exe
    if not errorlevel 1 hangman.exe
)
if errorlevel 2 (
    cd 02_Камень_ножницы_бумага
    g++ game.cpp -o rps.exe
    if not errorlevel 1 rps.exe
)
if errorlevel 1 (
    cd 01_Угадай_число
    g++ game.cpp -o guess.exe
    if not errorlevel 1 guess.exe
)
cd ..
pause
goto menu

:check_gcc
cls
call ПРОВЕРКА_G++.bat
goto menu

:update_path
cls
call ОБНОВИТЬ_PATH.bat
goto menu

:test_compile
cls
call ТЕСТ_КОМПИЛЯЦИИ.bat
goto menu

:test_encoding
cls
call ТЕСТ_КОДИРОВКИ.bat
goto menu

:demo_guards
cls
cd "05_Указатели_и_ссылки\примеры_с_заголовками\demo_include_guards"
call ЗАПУСТИТЬ_ВСЕ_ТЕСТЫ.bat
cd ..\..\..
goto menu

:compile_examples
cls
cd "05_Указатели_и_ссылки\примеры_с_заголовками"
call КОМПИЛЯЦИЯ_ВСЕХ_ПРИМЕРОВ.bat
cd ..\..
goto menu

:opencmd
start cmd /k "chcp 65001 && cd /d \"%~dp0\" && echo. && echo ═══ КОМАНДНАЯ СТРОКА ═══ && echo. && echo Вы в папке проекта. Команды: && echo   g++ --version          - проверить компилятор && echo   g++ main.cpp -o prog   - скомпилировать && echo   dir *.cpp              - список файлов && echo."
goto menu

:doc1
start README.md
goto menu

:doc2
start КАК_КОМПИЛИРОВАТЬ.md
goto menu
