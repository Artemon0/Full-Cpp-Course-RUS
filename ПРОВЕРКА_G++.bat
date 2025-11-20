@echo off
chcp 65001 > nul

echo ╔════════════════════════════════════════╗
echo ║   БЫСТРАЯ ПРОВЕРКА G++                 ║
echo ╚════════════════════════════════════════╝
echo.

echo Проверка g++...
echo.

where g++ > nul 2>&1

if %ERRORLEVEL% EQU 0 (
    echo ✅ g++ НАЙДЕН!
    echo.
    echo Версия:
    g++ --version
    echo.
    echo ════════════════════════════════════════
    echo Путь к g++:
    where g++
    echo ════════════════════════════════════════
    echo.
    echo ✅ ВСЕ РАБОТАЕТ! Можете компилировать.
    echo.
    echo Пример:
    echo   g++ main.cpp -o program.exe
    echo.
) else (
    echo ❌ g++ НЕ НАЙДЕН!
    echo.
    echo ════════════════════════════════════════
    echo ВОЗМОЖНЫЕ ПРИЧИНЫ:
    echo ════════════════════════════════════════
    echo.
    echo 1. Компилятор не установлен
    echo    Решение: Установите MSYS2
    echo    https://www.msys2.org/
    echo.
    echo 2. Не добавлен в PATH
    echo    Решение: Добавьте путь к bin в PATH
    echo    Например: C:\msys64\mingw64\bin
    echo.
    echo 3. Нужно перезапустить терминал
    echo    Решение: Закройте и откройте заново
    echo.
    echo ════════════════════════════════════════
    echo.
    echo Запустите для подробной диагностики:
    echo   .\ПРОВЕРКА_УСТАНОВКИ.ps1
    echo.
)

echo.
echo Нажмите любую клавишу для выхода...
pause > nul
