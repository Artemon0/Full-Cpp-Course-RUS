# Скрипт проверки установки компилятора
# Запуск: .\ПРОВЕРКА_УСТАНОВКИ.ps1

Write-Host "╔════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "║   ДИАГНОСТИКА КОМПИЛЯТОРА              ║" -ForegroundColor Cyan
Write-Host "╚════════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

# Проверка 1: Команда g++ доступна?
Write-Host "[1/5] Проверка команды g++..." -ForegroundColor Yellow
$gppCommand = Get-Command g++ -ErrorAction SilentlyContinue

if ($gppCommand) {
    Write-Host "✅ g++ найден!" -ForegroundColor Green
    Write-Host "   Путь: $($gppCommand.Source)" -ForegroundColor Gray
    Write-Host ""
    
    Write-Host "   Версия:" -ForegroundColor Gray
    g++ --version
} else {
    Write-Host "❌ g++ НЕ найден в PATH" -ForegroundColor Red
}
Write-Host ""

# Проверка 2: Поиск g++ в системе
Write-Host "[2/5] Поиск g++ в системе..." -ForegroundColor Yellow

$possiblePaths = @(
    "C:\msys64\mingw64\bin\g++.exe",
    "C:\msys64\ucrt64\bin\g++.exe",
    "C:\mingw64\bin\g++.exe",
    "C:\MinGW\bin\g++.exe",
    "C:\Program Files\mingw-w64\bin\g++.exe",
    "C:\TDM-GCC-64\bin\g++.exe"
)

$found = $false
foreach ($path in $possiblePaths) {
    if (Test-Path $path) {
        Write-Host "✅ Найден: $path" -ForegroundColor Green
        $found = $true
        
        # Проверяем, есть ли этот путь в PATH
        $binPath = Split-Path $path
        if ($env:Path -like "*$binPath*") {
            Write-Host "   ✅ Путь УЖЕ в PATH" -ForegroundColor Green
        } else {
            Write-Host "   ⚠️  Путь НЕ в PATH!" -ForegroundColor Yellow
            Write-Host "   Добавьте в PATH: $binPath" -ForegroundColor Yellow
        }
    }
}

if (-not $found) {
    Write-Host "❌ g++ не найден в стандартных местах" -ForegroundColor Red
}
Write-Host ""

# Проверка 3: Текущий PATH
Write-Host "[3/5] Проверка PATH..." -ForegroundColor Yellow
$pathEntries = $env:Path -split ';' | Where-Object { $_ -match 'mingw|msys|gcc|tdm' }

if ($pathEntries) {
    Write-Host "✅ Найдены записи в PATH:" -ForegroundColor Green
    foreach ($entry in $pathEntries) {
        Write-Host "   - $entry" -ForegroundColor Gray
    }
} else {
    Write-Host "❌ Нет записей mingw/msys в PATH" -ForegroundColor Red
}
Write-Host ""

# Проверка 4: Системный PATH
Write-Host "[4/5] Проверка системного PATH..." -ForegroundColor Yellow
try {
    $systemPath = [Environment]::GetEnvironmentVariable("Path", "Machine")
    $userPath = [Environment]::GetEnvironmentVariable("Path", "User")
    
    $systemGcc = $systemPath -split ';' | Where-Object { $_ -match 'mingw|msys|gcc' }
    $userGcc = $userPath -split ';' | Where-Object { $_ -match 'mingw|msys|gcc' }
    
    if ($systemGcc) {
        Write-Host "✅ В системном PATH:" -ForegroundColor Green
        foreach ($entry in $systemGcc) {
            Write-Host "   - $entry" -ForegroundColor Gray
        }
    }
    
    if ($userGcc) {
        Write-Host "✅ В пользовательском PATH:" -ForegroundColor Green
        foreach ($entry in $userGcc) {
            Write-Host "   - $entry" -ForegroundColor Gray
        }
    }
    
    if (-not $systemGcc -and -not $userGcc) {
        Write-Host "❌ Нет записей в системном PATH" -ForegroundColor Red
    }
} catch {
    Write-Host "⚠️  Не удалось прочитать системный PATH" -ForegroundColor Yellow
}
Write-Host ""

# Проверка 5: Рекомендации
Write-Host "[5/5] Рекомендации..." -ForegroundColor Yellow
Write-Host ""

if (-not $gppCommand) {
    Write-Host "════════════════════════════════════════" -ForegroundColor Red
    Write-Host "РЕШЕНИЕ:" -ForegroundColor Red
    Write-Host "════════════════════════════════════════" -ForegroundColor Red
    Write-Host ""
    
    if ($found) {
        Write-Host "g++ установлен, но не в PATH!" -ForegroundColor Yellow
        Write-Host ""
        Write-Host "Вариант 1: Обновите PATH в текущей сессии" -ForegroundColor Cyan
        Write-Host "   .\ОБНОВИТЬ_PATH.bat" -ForegroundColor Gray
        Write-Host ""
        Write-Host "Вариант 2: Перезапустите PowerShell" -ForegroundColor Cyan
        Write-Host "   Закройте это окно и откройте новое" -ForegroundColor Gray
        Write-Host ""
        Write-Host "Вариант 3: Добавьте в PATH вручную" -ForegroundColor Cyan
        Write-Host "   1. Win + R → sysdm.cpl" -ForegroundColor Gray
        Write-Host "   2. Дополнительно → Переменные среды" -ForegroundColor Gray
        Write-Host "   3. Path → Изменить → Добавить путь к bin" -ForegroundColor Gray
    } else {
        Write-Host "g++ не установлен!" -ForegroundColor Yellow
        Write-Host ""
        Write-Host "Установите MSYS2:" -ForegroundColor Cyan
        Write-Host "   1. https://www.msys2.org/" -ForegroundColor Gray
        Write-Host "   2. Запустите MSYS2" -ForegroundColor Gray
        Write-Host "   3. pacman -Syu" -ForegroundColor Gray
        Write-Host "   4. pacman -S mingw-w64-x86_64-gcc" -ForegroundColor Gray
        Write-Host "   5. Добавьте C:\msys64\mingw64\bin в PATH" -ForegroundColor Gray
    }
} else {
    Write-Host "════════════════════════════════════════" -ForegroundColor Green
    Write-Host "✅ ВСЕ РАБОТАЕТ!" -ForegroundColor Green
    Write-Host "════════════════════════════════════════" -ForegroundColor Green
    Write-Host ""
    Write-Host "Можете компилировать программы:" -ForegroundColor Cyan
    Write-Host "   g++ main.cpp -o program.exe" -ForegroundColor Gray
}

Write-Host ""
Write-Host "Нажмите Enter для выхода..."
$null = Read-Host
