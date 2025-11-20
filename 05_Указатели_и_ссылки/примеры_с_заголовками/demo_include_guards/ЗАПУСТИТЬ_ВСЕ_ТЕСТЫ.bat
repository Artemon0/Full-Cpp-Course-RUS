@echo off
chcp 65001 > nul
cls

echo ╔════════════════════════════════════════╗
echo ║   ДЕМОНСТРАЦИЯ INCLUDE GUARDS          ║
echo ╚════════════════════════════════════════╝
echo.

echo Эта демонстрация покажет:
echo 1. Проблему БЕЗ include guards
echo 2. Решение С include guards
echo.

pause

echo.
echo ════════════════════════════════════════
echo ШАГИ ДЕМОНСТРАЦИИ:
echo ════════════════════════════════════════
echo.

REM Проверка компилятора
echo [1/3] Проверка компилятора...
where g++ > nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ❌ Компилятор g++ не найден!
    echo.
    echo Запустите ПРОВЕРКА_КОМПИЛЯТОРА.bat
    echo для получения инструкций по установке.
    echo.
    pause
    exit /b 1
)
echo ✅ Компилятор найден
echo.

REM Тест БЕЗ guards
echo [2/3] Тест БЕЗ include guards...
echo.
echo Компиляция test_without.cpp...
g++ test_without.cpp -o test_without.exe 2> error.txt

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ❌ Ожидаемая ошибка компиляции!
    echo.
    echo Ошибка:
    type error.txt
    echo.
    echo ════════════════════════════════════════
    echo ВЫВОД:
    echo БЕЗ include guards файл нельзя включить
    echo дважды - возникает ошибка повторного
    echo определения.
    echo ════════════════════════════════════════
) else (
    echo ⚠️ Неожиданно: компиляция успешна
)

del error.txt 2> nul
echo.
pause

REM Тест С guards
echo.
echo [3/3] Тест С include guards...
echo.
echo Компиляция test_with.cpp...
g++ test_with.cpp -o test_with.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ✅ Успешно скомпилировано!
    echo.
    echo Запуск программы...
    echo ════════════════════════════════════════
    echo.
    test_with.exe
    echo.
    echo ════════════════════════════════════════
    echo ВЫВОД:
    echo С include guards файл можно включать
    echo сколько угодно раз - проблем не будет!
    echo ════════════════════════════════════════
) else (
    echo ❌ Ошибка компиляции
)

echo.
echo.
echo ╔════════════════════════════════════════╗
echo ║   ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА               ║
echo ╚════════════════════════════════════════╝
echo.
echo Теперь вы понимаете, зачем нужны
echo include guards!
echo.
echo Читайте:
echo - INCLUDE_GUARDS_ОБЪЯСНЕНИЕ.md
echo - ШПАРГАЛКА_INCLUDE_GUARDS.md
echo.

pause
