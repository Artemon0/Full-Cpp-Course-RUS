@echo off
chcp 65001 > nul
setlocal enabledelayedexpansion

cls
echo ╔════════════════════════════════════════╗
echo ║   КОМПИЛЯЦИЯ ЛЮБОГО УРОКА              ║
echo ╚════════════════════════════════════════╝
echo.

REM Проверка компилятора
where g++ > nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ❌ Компилятор g++ не найден!
    echo.
    echo Запустите: ПРОВЕРКА_G++.bat
    echo.
    pause
    exit /b 1
)

REM Если передан аргумент - компилируем его
if not "%~1"=="" (
    set "file=%~1"
    goto compile
)

REM Иначе показываем меню
:menu
cls
echo.
echo ╔════════════════════════════════════════╗
echo ║   ВЫБЕРИТЕ РАЗДЕЛ                      ║
echo ╚════════════════════════════════════════╝
echo.
echo  1. Основы
echo  2. Управляющие конструкции
echo  3. Функции
echo  4. Массивы и строки
echo  5. Указатели и ссылки
echo  6. ООП
echo  7. STL
echo  8. Файлы
echo  9. Продвинутые темы
echo  G. Игры
echo.
echo  0. Выход
echo.

choice /c 123456789G0 /n /m "Ваш выбор: "

if errorlevel 11 exit /b
if errorlevel 10 goto games
if errorlevel 9 goto section9
if errorlevel 8 goto section8
if errorlevel 7 goto section7
if errorlevel 6 goto section6
if errorlevel 5 goto section5
if errorlevel 4 goto section4
if errorlevel 3 goto section3
if errorlevel 2 goto section2
if errorlevel 1 goto section1

:section1
set "folder=01_Основы"
goto select_file

:section2
set "folder=02_Управляющие_конструкции"
goto select_file

:section3
set "folder=03_Функции"
goto select_file

:section4
set "folder=04_Массивы_и_строки"
goto select_file

:section5
set "folder=05_Указатели_и_ссылки"
goto select_file

:section6
set "folder=06_ООП"
goto select_file

:section7
set "folder=07_STL"
goto select_file

:section8
set "folder=08_Файлы"
goto select_file

:section9
set "folder=09_Продвинутые_темы"
goto select_file

:games
set "folder=Игры"
goto select_game

:select_game
cls
echo.
echo ╔════════════════════════════════════════╗
echo ║   ВЫБЕРИТЕ ИГРУ                        ║
echo ╚════════════════════════════════════════╝
echo.
echo  1. Угадай число
echo  2. Камень, ножницы, бумага
echo  3. Виселица
echo  4. Крестики-нолики
echo.
echo  0. Назад
echo.

choice /c 12340 /n /m "Ваш выбор: "

if errorlevel 5 goto menu
if errorlevel 4 set "file=Игры\04_Крестики_нолики\game.cpp" & goto compile
if errorlevel 3 set "file=Игры\03_Виселица\game.cpp" & goto compile
if errorlevel 2 set "file=Игры\02_Камень_ножницы_бумага\game.cpp" & goto compile
if errorlevel 1 set "file=Игры\01_Угадай_число\game.cpp" & goto compile

:select_file
cls
echo.
echo ╔════════════════════════════════════════╗
echo ║   ФАЙЛЫ В ПАПКЕ: %folder%
echo ╚════════════════════════════════════════╝
echo.

set count=0
for %%f in ("%folder%\*.cpp") do (
    set /a count+=1
    set "file!count!=%%f"
    echo  !count!. %%~nxf
)

if %count%==0 (
    echo  Нет .cpp файлов в этой папке
    echo.
    pause
    goto menu
)

echo.
echo  0. Назад
echo.

set /p choice="Выберите номер файла (0-%count%): "

if "%choice%"=="0" goto menu
if %choice% LEQ 0 goto select_file
if %choice% GTR %count% goto select_file

set "file=!file%choice%!"

:compile
cls
echo.
echo ╔════════════════════════════════════════╗
echo ║   КОМПИЛЯЦИЯ                           ║
echo ╚════════════════════════════════════════╝
echo.

echo Файл: %file%
echo.

REM Получаем имя без расширения
for %%f in ("%file%") do set "basename=%%~nf"
set "output=%basename%.exe"

echo Компиляция...
echo ════════════════════════════════════════
g++ "%file%" -o "%output%" 2>&1

if %ERRORLEVEL% NEQ 0 (
    echo ════════════════════════════════════════
    echo.
    echo ❌ Ошибка компиляции!
    echo.
    echo Проверьте код на ошибки.
    echo.
    pause
    goto menu
)

echo ════════════════════════════════════════
echo.
echo ✅ Компиляция успешна!
echo.
echo Создан файл: %output%
echo.

REM Спрашиваем, запустить ли программу
choice /c YN /m "Запустить программу? (Y/N)"

if errorlevel 2 goto menu

echo.
echo ════════════════════════════════════════
echo ВЫВОД ПРОГРАММЫ:
echo ════════════════════════════════════════
echo.

"%output%"

echo.
echo ════════════════════════════════════════
echo.

pause
goto menu
