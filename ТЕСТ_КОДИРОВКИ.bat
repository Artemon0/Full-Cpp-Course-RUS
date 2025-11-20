@echo off
chcp 65001 > nul
echo ========================================
echo   КОМПИЛЯЦИЯ И ЗАПУСК ТЕСТА КОДИРОВКИ
echo ========================================
echo.

echo Компиляция test_encoding.cpp...
g++ test_encoding.cpp -o test_encoding.exe

if %ERRORLEVEL% EQU 0 (
    echo Компиляция успешна!
    echo.
    echo Запуск программы...
    echo ========================================
    echo.
    test_encoding.exe
) else (
    echo.
    echo ОШИБКА: Компиляция не удалась!
    echo.
    echo Возможные причины:
    echo 1. Компилятор g++ не установлен
    echo 2. g++ не добавлен в PATH
    echo.
    echo Решение:
    echo - Установите MinGW или MSYS2
    echo - Добавьте путь к g++ в переменную PATH
    echo.
)

echo.
pause
