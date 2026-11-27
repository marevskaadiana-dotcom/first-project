#define NOMINMAX
#include <iostream>
#include <cmath> // Для математических функций (sqrt, pow, sin, cos, log)
#include <limits> 
#include <string>
#include <Windows.h>

// Прототипы функций
// Вспомогательные функции
void printMenu();
double getValidDouble(const std::string& prompt);
int getValidInt(const std::string& prompt);

// Математические операции (11 штук)
void opAdd();
void opSubtract();
void opMultiply();
void opDivide();
void opPower();
void opSquareRoot();
void opModulo();
void opAbsolute();
void opSine();
void opCosine();
void opLogarithm();

// Главная функция
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int choice;
    do {
        printMenu();
        choice = getValidInt("Ваш выбор (0-11): ");
        switch (choice) {
            case 1:  opAdd(); break;
            case 2:  opSubtract(); break;
            case 3:  opMultiply(); break;
            case 4:  opDivide(); break;
            case 5:  opPower(); break;
            case 6:  opSquareRoot(); break;
            case 7:  opModulo(); break;
            case 8:  opAbsolute(); break;
            case 9:  opSine(); break;
            case 10: opCosine(); break;
            case 11: opLogarithm(); break;
            case 0:  std::cout << "Выход из программы.\n"; break;
            default: std::cout << "ОШИБКА: Неверный пункт меню.\n"; break;
        }
    } while (choice != 0);

    return 0;
}

// Реализация вспомогательных функций

void printMenu() {
    std::cout << "\nКалькулятор\n";
    std::cout << "1. Сложение\n";
    std::cout << "2. Вычитание\n";
    std::cout << "3. Умножение\n";
    std::cout << "4. Деление\n";
    std::cout << "5. Возведение в степень\n";
    std::cout << "6. Квадратный корень\n";
    std::cout << "7. Остаток от деления (для целых)\n";
    std::cout << "8. Модуль числа (абсолютное значение)\n";
    std::cout << "9. Синус (в радианах)\n";
    std::cout << "10. Косинус (в радианах)\n";
    std::cout << "11. Натуральный логарифм (ln)\n";
    std::cout << "0. Выход\n";
}

// Безопасный ввод вещественного числа
double getValidDouble(const std::string& prompt) {
    double val;
    std::cout << prompt;
    while (!(std::cin >> val)) {
        std::cout << "ОШИБКА! Введите корректное число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return val;
}

// Безопасный ввод целого числа
int getValidInt(const std::string& prompt) {
    int val;
    std::cout << prompt;
    while (!(std::cin >> val)) {
        std::cout << "ОШИБКА! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return val;
}

// Реализация математических функций

void opAdd() {
    double a = getValidDouble("Введите первое слагаемое: ");
    double b = getValidDouble("Введите второе слагаемое: ");
    std::cout << "Результат: " << a + b << "\n";
}

void opSubtract() {
    double a = getValidDouble("Введите уменьшаемое: ");
    double b = getValidDouble("Введите вычитаемое: ");
    std::cout << "Результат: " << a - b << "\n";
}

void opMultiply() {
    double a = getValidDouble("Введите первый множитель: ");
    double b = getValidDouble("Введите второй множитель: ");
    std::cout << "Результат: " << a * b << "\n";
}

void opDivide() {
    double a = getValidDouble("Введите делимое: ");
    double b = getValidDouble("Введите делитель: ");
    
    // Защита от деления на ноль
    if (b == 0.0) {
        std::cout << "ОШИБКА: Деление на ноль невозможно!\n";
    } else {
        std::cout << "Результат: " << a / b << "\n";
    }
}

void opPower() {
    double base = getValidDouble("Введите основание: ");
    double exp = getValidDouble("Введите степень: ");
    std::cout << "Результат: " << std::pow(base, exp) << "\n";
}

void opSquareRoot() {
    double a = getValidDouble("Введите число: ");
    
    // Защита от извлечения корня из отрицательного числа
    if (a < 0) {
        std::cout << "ОШИБКА: Квадратный корень из отрицательного числа не существует (в действительных числах)!\n";
    } else {
        std::cout << "Результат: " << std::sqrt(a) << "\n";
    }
}

void opModulo() {
    int a = getValidInt("Введите делимое (целое): ");
    int b = getValidInt("Введите делитель (целое): ");
    
    if (b == 0) {
        std::cout << "ОШИБКА: Деление на ноль невозможно!\n";
    } else {
        std::cout << "Остаток от деления: " << a % b << "\n";
    }
}

void opAbsolute() {
    double a = getValidDouble("Введите число: ");
    std::cout << "Модуль числа: " << std::abs(a) << "\n";
}

void opSine() {
    double a = getValidDouble("Введите угол в радианах: ");
    std::cout << "Синус: " << std::sin(a) << "\n";
}

void opCosine() {
    double a = getValidDouble("Введите угол в радианах: ");
    std::cout << "Косинус: " << std::cos(a) << "\n";
}

void opLogarithm() {
    double a = getValidDouble("Введите число для вычисления ln: ");
    
    // Защита области определения логарифма
    if (a <= 0) {
        std::cout << "ОШИБКА: Логарифм определен только для положительных чисел!\n";
    } else {
        std::cout << "Натуральный логарифм: " << std::log(a) << "\n";
    }
}