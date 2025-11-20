@echo off
chcp 65001 > nul
echo ╔════════════════════════════════════════╗
echo ║   ОБНОВЛЕНИЕ PATH В ТЕКУЩЕЙ СЕССИИ     ║
echo ╚════════════════════════════════════════╝
echo.

echo Эта команда обновит PATH в текущем окне
echo без перезапуска PowerShell/CMD
echo.

echo Обновление переменных окружения...
echo.

REM Обновляем PATH из реестра
for /f "tokens=2*" %%a in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v Path') do set "SystemPath=%%b"
for /f "tokens=2*" %%a in ('reg query "HKCU\Environment" /v Path') do set "UserPath=%%b"

set "Path=%SystemPath%;%UserPath%"

echo ✅ PATH обновлен!
echo.

echo Проверка g++...
where g++ > nul 2>&1

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ✅ g++ найден!
    echo.
    g++ --version
    echo.
    echo ════════════════════════════════════════
    echo Теперь можно компилировать!
    echo ════════════════════════════════════════
) else (
    echo.
    echo ❌ g++ все еще не найден
    echo.
    echo Возможные причины:
    echo 1. PATH не был добавлен в системные переменные
    echo 2. Нужно перезагрузить компьютер
    echo 3. g++ установлен в нестандартное место
    echo.
    echo Текущий PATH:
    echo %Path%
    echo.
)

echo.
echo Нажмите любую клавишу для выхода...
pause > nul
