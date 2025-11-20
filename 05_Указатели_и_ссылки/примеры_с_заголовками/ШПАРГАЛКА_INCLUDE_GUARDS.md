# 📋 Шпаргалка: Include Guards

## 🎯 Что это?

```cpp
#ifndef MATH_H
#define MATH_H

// Ваш код

#endif
```

**Защита от повторного включения файла**

---

## ⚡ Быстрое объяснение

### Без защиты (ПЛОХО ❌):
```cpp
// math.h
int add(int a, int b);
```

```cpp
// main.cpp
#include "math.h"
#include "math.h"  // ← ОШИБКА! Повторное объявление
```

### С защитой (ХОРОШО ✅):
```cpp
// math.h
#ifndef MATH_H
#define MATH_H

int add(int a, int b);

#endif
```

```cpp
// main.cpp
#include "math.h"
#include "math.h"  // ← ОК! Защита работает
```

---

## 🔍 Как это работает?

### Первое включение:
```cpp
#ifndef MATH_H    // MATH_H не определен? → ДА
#define MATH_H    // Определяем MATH_H
                  // Обрабатываем код
#endif
```

### Второе включение:
```cpp
#ifndef MATH_H    // MATH_H не определен? → НЕТ
                  // ПРОПУСКАЕМ весь блок
#endif
```

---

## 📝 Шаблон для копирования

```cpp
#ifndef FILENAME_H
#define FILENAME_H

// Ваш код здесь

#endif
```

**Замените `FILENAME` на имя вашего файла!**

---

## 🎨 Примеры

### calculator.h
```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
    // ...
};

#endif
```

### student.h
```cpp
#ifndef STUDENT_H
#define STUDENT_H

class Student {
    // ...
};

#endif
```

### my_utils.h
```cpp
#ifndef MY_UTILS_H
#define MY_UTILS_H

void myFunction();

#endif
```

---

## 🎓 Правила именования

| Имя файла | Include Guard |
|-----------|---------------|
| `math.h` | `MATH_H` |
| `calculator.h` | `CALCULATOR_H` |
| `my_class.h` | `MY_CLASS_H` |
| `utils-helper.h` | `UTILS_HELPER_H` |

**Правило:**
1. Имя файла ЗАГЛАВНЫМИ буквами
2. Точки и дефисы → подчеркивания
3. Добавить `_H` в конце

---

## ⚠️ Частые ошибки

### ❌ Забыли #endif
```cpp
#ifndef MATH_H
#define MATH_H

int add(int a, int b);

// ← Где #endif?
```

### ❌ Опечатка
```cpp
#ifndef MATH_H
#define MAHT_H  // ← Опечатка!

int add(int a, int b);

#endif
```

### ❌ Не уникальное имя
```cpp
// file1.h
#ifndef UTILS_H  // ← Общее имя
#define UTILS_H
// ...
#endif

// file2.h
#ifndef UTILS_H  // ← То же имя!
#define UTILS_H
// ...
#endif
```

---

## 🆚 Альтернатива: #pragma once

### Традиционный способ:
```cpp
#ifndef MATH_H
#define MATH_H

int add(int a, int b);

#endif
```

### Современный способ:
```cpp
#pragma once

int add(int a, int b);
```

**Оба работают!** Но `#ifndef/#define/#endif` более переносимый.

---

## ✅ Чек-лист

При создании `.h` файла:

- [ ] Добавил `#ifndef FILENAME_H`
- [ ] Добавил `#define FILENAME_H`
- [ ] Написал код
- [ ] Добавил `#endif`
- [ ] Имя уникальное
- [ ] Нет опечаток

---

## 🚀 Быстрый старт

1. Создайте файл `myfile.h`
2. Скопируйте шаблон:
```cpp
#ifndef MYFILE_H
#define MYFILE_H

// Ваш код

#endif
```
3. Замените `MYFILE` на имя вашего файла
4. Готово!

---

## 📚 Дополнительно

- `INCLUDE_GUARDS_ОБЪЯСНЕНИЕ.md` - полное объяснение
- `demo_include_guards/` - практические примеры
- `ПОДРОБНОЕ_РУКОВОДСТВО.md` - все о заголовочных файлах

---

## 💡 Запомните

> **ВСЕГДА используйте include guards в каждом .h файле!**

Это предотвращает ошибки при сложных зависимостях между файлами.

---

## 🎯 Итог

```cpp
// Это ВСЁ, что нужно запомнить:

#ifndef FILENAME_H
#define FILENAME_H

// Ваш код

#endif
```

Просто, но очень важно! 🎉
