@echo off
chcp 65001 > nul
cls

echo ╔════════════════════════════════════════╗
echo ║   ЗАПУСК В КОМАНДНОЙ СТРОКЕ            ║
echo ╚════════════════════════════════════════╝
echo.

echo Этот скрипт откроет новое окно CMD,
echo которое НЕ закроется автоматически.
echo.

echo Выберите действие:
echo.
echo 1. Проверить компилятор
echo 2. Обновить PATH
echo 3. Открыть CMD в этой папке
echo 4. Выход
echo.

choice /c 1234 /n /m "Ваш выбор (1-4): "

if errorlevel 4 exit /b
if errorlevel 3 goto opencmd
if errorlevel 2 goto updatepath
if errorlevel 1 goto checkcompiler

:checkcompiler
start cmd /k "chcp 65001 > nul && echo. && echo ═══ ПРОВЕРКА КОМПИЛЯТОРА ═══ && echo. && g++ --version && echo. && echo Если видите версию - компилятор работает! && echo Если ошибка - компилятор не найден. && echo. && echo Закройте это окно когда закончите."
goto end

:updatepath
start cmd /k "chcp 65001 > nul && echo. && echo ═══ ОБНОВЛЕНИЕ PATH ═══ && echo. && for /f \"tokens=2*\" %%a in ('reg query \"HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment\" /v Path') do set \"SystemPath=%%b\" && for /f \"tokens=2*\" %%a in ('reg query \"HKCU\Environment\" /v Path') do set \"UserPath=%%b\" && set \"Path=%SystemPath%;%UserPath%\" && echo PATH обновлен! && echo. && g++ --version && echo. && echo Закройте это окно когда закончите."
goto end

:opencmd
start cmd /k "chcp 65001 && cd /d \"%~dp0\" && echo. && echo ═══ КОМАНДНАЯ СТРОКА ═══ && echo. && echo Вы находитесь в папке проекта. && echo Можете выполнять команды: && echo. && echo   g++ --version          - проверить компилятор && echo   g++ main.cpp -o prog   - скомпилировать && echo   dir *.cpp              - список файлов && echo. && echo Окно не закроется автоматически."
goto end

:end
exit /b
