#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>

// Прототип функции
// Объявляем функцию до main, чтобы компилятор знал о её существовании
int min(int a, int b);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int num1, num2;
    // Ввод первого числа с защитой от ошибок
    std::cout << "Введите первое число: ";
    while (!(std::cin >> num1)) {
        std::cout << "ОШИБКА! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Ввод второго числа с защитой от ошибок
    std::cout << "Введите второе число: ";
    while (!(std::cin >> num2)) {
        std::cout << "ОШИБКА! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Вызов функции
    // Передаем в функцию две переменные, результат сохраняем в result
    int result = min(num1, num2);

    std::cout << "Минимальное число: " << result << std::endl;

    return 0;
}

// Определение функции
// Функция принимает два целых числа (параметры a и b) и возвращает целое число (int)
int min(int a, int b) {
    if (a < b) {
        return a; // Если a меньше b, возвращаем a
    } else {
        return b; // Иначе возвращаем b
    }
}