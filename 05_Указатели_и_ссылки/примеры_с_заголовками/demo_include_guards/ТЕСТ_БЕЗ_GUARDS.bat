@echo off
chcp 65001 > nul
echo ╔════════════════════════════════════════╗
echo ║   ТЕСТ: БЕЗ INCLUDE GUARDS             ║
echo ╚════════════════════════════════════════╝
echo.

echo Этот тест демонстрирует ПРОБЛЕМУ
echo когда заголовочный файл НЕ защищен.
echo.

echo Попытка компиляции test_without.cpp...
echo.

g++ test_without.cpp -o test_without.exe 2>&1

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ════════════════════════════════════════
    echo ❌ ОЖИДАЕМЫЙ РЕЗУЛЬТАТ: ОШИБКА!
    echo ════════════════════════════════════════
    echo.
    echo Вы должны увидеть ошибку типа:
    echo   "redefinition of 'int dangerousFunction()'"
    echo   "redefinition of 'class DangerousClass'"
    echo.
    echo ПРИЧИНА:
    echo Файл without_guards.h включен дважды,
    echo и его содержимое обработано два раза.
    echo.
    echo РЕШЕНИЕ:
    echo Используйте include guards!
    echo См. файл with_guards.h
    echo.
) else (
    echo.
    echo ════════════════════════════════════════
    echo ⚠️ НЕОЖИДАННО: Компиляция успешна
    echo ════════════════════════════════════════
    echo.
    echo Возможно, компилятор оптимизировал код
    echo или есть другие факторы.
    echo.
)

echo Нажмите любую клавишу для выхода...
pause > nul
