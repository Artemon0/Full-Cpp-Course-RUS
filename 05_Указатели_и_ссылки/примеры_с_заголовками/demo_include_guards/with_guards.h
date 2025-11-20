#ifndef WITH_GUARDS_H
#define WITH_GUARDS_H

/*
 * ХОРОШИЙ ПРИМЕР: Заголовок С include guards
 * 
 * Этот файл защищен от повторного включения
 * Можно включать сколько угодно раз - проблем не будет!
 */

int safeFunction();

class SafeClass {
public:
    void method();
};

#endif // WITH_GUARDS_H

/*
 * ПРЕИМУЩЕСТВО:
 * Этот файл можно включить много раз - ошибок не будет!
 * Include guards гарантируют, что содержимое обработается только один раз.
 */
