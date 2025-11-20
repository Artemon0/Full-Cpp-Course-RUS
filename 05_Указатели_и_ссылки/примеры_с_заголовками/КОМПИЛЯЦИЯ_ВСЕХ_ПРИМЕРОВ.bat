@echo off
chcp 65001 > nul
echo ╔════════════════════════════════════════╗
echo ║   КОМПИЛЯЦИЯ ВСЕХ ПРИМЕРОВ             ║
echo ╚════════════════════════════════════════╝
echo.

echo [1/4] Компиляция math примера...
g++ main.cpp math.cpp -o math_demo.exe
if %ERRORLEVEL% EQU 0 (
    echo ✓ math_demo.exe создан
) else (
    echo ✗ Ошибка компиляции math
)
echo.

echo [2/4] Компиляция Student примера...
g++ main_student.cpp Student.cpp -o students.exe
if %ERRORLEVEL% EQU 0 (
    echo ✓ students.exe создан
) else (
    echo ✗ Ошибка компиляции Student
)
echo.

echo [3/4] Компиляция Calculator примера...
g++ main_calculator.cpp Calculator.cpp -o calculator.exe
if %ERRORLEVEL% EQU 0 (
    echo ✓ calculator.exe создан
) else (
    echo ✗ Ошибка компиляции Calculator
)
echo.

echo [4/4] Компиляция Array примера...
g++ main_array.cpp Array.cpp -o array_demo.exe
if %ERRORLEVEL% EQU 0 (
    echo ✓ array_demo.exe создан
) else (
    echo ✗ Ошибка компиляции Array
)
echo.

echo ════════════════════════════════════════
echo Компиляция завершена!
echo.
echo Запустите программы:
echo   math_demo.exe
echo   students.exe
echo   calculator.exe
echo   array_demo.exe
echo ════════════════════════════════════════
echo.
pause
