/*
 * ПЛОХОЙ ПРИМЕР: Заголовок БЕЗ include guards
 * 
 * ВНИМАНИЕ: Этот файл специально создан БЕЗ защиты
 * для демонстрации проблемы!
 * 
 * НЕ ИСПОЛЬЗУЙТЕ такой подход в реальных проектах!
 */

// НЕТ #ifndef
// НЕТ #define

int dangerousFunction();

class DangerousClass {
public:
    void method();
};

// НЕТ #endif

/*
 * ПРОБЛЕМА:
 * Если этот файл включить дважды, будет ошибка:
 * "redefinition of 'dangerousFunction'"
 * "redefinition of 'class DangerousClass'"
 */
