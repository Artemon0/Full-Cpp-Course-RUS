@echo off
chcp 65001 > nul

echo ╔════════════════════════════════════════╗
echo ║   ТЕСТ КОМПИЛЯЦИИ                      ║
echo ╚════════════════════════════════════════╝
echo.

echo Этот скрипт создаст простую программу,
echo скомпилирует и запустит её.
echo.

REM Проверка g++
where g++ > nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ❌ g++ не найден!
    echo.
    echo Запустите сначала:
    echo   ПРОВЕРКА_G++.bat
    echo.
    pause
    exit /b 1
)

echo [1/4] Создание тестового файла...
echo #include ^<iostream^> > test_compile.cpp
echo #include ^<windows.h^> >> test_compile.cpp
echo using namespace std; >> test_compile.cpp
echo int main() { >> test_compile.cpp
echo     SetConsoleOutputCP(CP_UTF8); >> test_compile.cpp
echo     SetConsoleCP(CP_UTF8); >> test_compile.cpp
echo     cout ^<^< "✅ Компиляция успешна!" ^<^< endl; >> test_compile.cpp
echo     cout ^<^< "✅ Программа работает!" ^<^< endl; >> test_compile.cpp
echo     cout ^<^< "✅ Русский текст отображается!" ^<^< endl; >> test_compile.cpp
echo     return 0; >> test_compile.cpp
echo } >> test_compile.cpp
echo ✅ Файл создан
echo.

echo [2/4] Компиляция...
g++ test_compile.cpp -o test_compile.exe

if %ERRORLEVEL% NEQ 0 (
    echo ❌ Ошибка компиляции!
    echo.
    del test_compile.cpp 2> nul
    pause
    exit /b 1
)
echo ✅ Компиляция успешна
echo.

echo [3/4] Запуск программы...
echo ════════════════════════════════════════
test_compile.exe
echo ════════════════════════════════════════
echo.

echo [4/4] Очистка...
del test_compile.cpp test_compile.exe 2> nul
echo ✅ Временные файлы удалены
echo.

echo ╔════════════════════════════════════════╗
echo ║   ТЕСТ ПРОЙДЕН УСПЕШНО!                ║
echo ╚════════════════════════════════════════╝
echo.
echo Теперь вы можете компилировать свои программы:
echo   g++ myfile.cpp -o myprogram.exe
echo.

pause
