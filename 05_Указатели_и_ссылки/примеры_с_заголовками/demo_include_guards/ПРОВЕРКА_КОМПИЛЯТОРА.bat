@echo off
chcp 65001 > nul
echo ╔════════════════════════════════════════╗
echo ║   ПРОВЕРКА КОМПИЛЯТОРА                 ║
echo ╚════════════════════════════════════════╝
echo.

echo Проверка наличия g++...
echo.

where g++ > nul 2>&1

if %ERRORLEVEL% EQU 0 (
    echo ✅ Компилятор g++ найден!
    echo.
    echo Версия:
    g++ --version
    echo.
    echo Путь:
    where g++
    echo.
    echo ════════════════════════════════════════
    echo Все готово для компиляции!
    echo ════════════════════════════════════════
) else (
    echo ❌ Компилятор g++ НЕ найден!
    echo.
    echo ════════════════════════════════════════
    echo РЕШЕНИЕ:
    echo ════════════════════════════════════════
    echo.
    echo 1. Установите MinGW-w64 или MSYS2
    echo.
    echo    MSYS2 (рекомендуется):
    echo    https://www.msys2.org/
    echo.
    echo    После установки выполните:
    echo    pacman -S mingw-w64-x86_64-gcc
    echo.
    echo 2. Добавьте путь к g++ в PATH:
    echo    Например: C:\msys64\mingw64\bin
    echo.
    echo 3. Перезапустите терминал
    echo.
    echo 4. Запустите этот скрипт снова
    echo.
    echo ════════════════════════════════════════
    echo.
    echo Подробная инструкция:
    echo См. файл КАК_КОМПИЛИРОВАТЬ.md
    echo в корне проекта
    echo.
)

echo.
pause
