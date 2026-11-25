#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
// Вспомогательная функция для безопасного ввода вещественных чисел
double getValidDouble(const std::string& prompt) {
    double val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val) return val;
        std::cout << "ОШИБКА! Введите число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
// Функция 1: Вычисление e^x через ряд Тейлора
double my_exp(double x, double eps) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    while (std::abs(term) > eps && n < 1000) {
        term *= x / n;
        sum += term;
        n++;
    }
    return sum;
}
// Функция 2: Вычисление sin(x) через ряд Тейлора
double my_sin(double x, double eps) {
    double sum = x;
    double term = x;
    int n = 1;
    while (std::abs(term) > eps && n < 1000) {
        // Следующий член: term * (-x^2) / ((2n) * (2n+1))
        term *= -1.0 * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}
// Функция 3: Вычисление ln(1+x) через ряд Тейлора
double my_ln(double x, double eps) {
    double sum = 0.0;
    double term = x;
    int n = 1;
    while (std::abs(term) > eps && n < 10000) { // Логарифм сходится медленно
        sum += term / n;
        term *= -x;
        n++;
    }
    return sum;
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int choice;
    std::cout << "ВЫБОР РЯДА ДЛЯ ВЫЧИСЛЕНИЯ\n";
    std::cout << "1 - e^x (Экспонента)\n";
    std::cout << "2 - sin(x) (Синус)\n";
    std::cout << "3 - ln(1+x) (Натуральный логарифм)\n";
    while (true) {
        std::cout << "Ваш выбор (1-3): ";
        if (std::cin >> choice && choice >= 1 && choice <= 3) break;
        std::cout << "ОШИБКА! Введите 1, 2 или 3.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    double eps = getValidDouble("Введите точность (например, 0.0001): ");
    if (eps <= 0) {
        std::cout << "ОШИБКА: Точность должна быть положительной!\n";
        return 1;
    }
    double start = getValidDouble("Введите начало интервала (x от): ");
    double end = getValidDouble("Введите конец интервала (x до): ");
    double step = getValidDouble("Введите шаг: ");
    if (start > end) {
        std::cout << "ОШИБКА: Начало интервала больше конца!\n";
        return 1;
    }
    if (step <= 0) {
        std::cout << "ОШИБКА: Шаг должен быть больше нуля!\n";
        return 1;
    }
    // Заголовок таблицы
    std::cout << "\n" << std::string(65, '-') << "\n";
    std::cout << std::setw(10) << "x" << " | " 
              << std::setw(12) << "Мой ряд" << " | " 
              << std::setw(12) << "Библиотека" << " | " 
              << std::setw(12) << "Разница" << "\n";
    std::cout << std::string(65, '-') << "\n";
    std::cout << std::fixed << std::setprecision(6);
    for (double x = start; x <= end + 1e-9; x += step) {
        double my_val = 0, std_val = 0;
        bool valid_point = true;
        // Вычисление в зависимости от выбора
        if (choice == 1) {
            my_val = my_exp(x, eps);
            std_val = std::exp(x);
        } 
        else if (choice == 2) {
            my_val = my_sin(x, eps);
            std_val = std::sin(x);
        } 
        else if (choice == 3) {
            // ОБРАБОТКА ОСОБЫХ ТОЧЕК (Область сходимости ряда)
            if (x <= -1.0 || x > 1.0) {
                valid_point = false;
            } else {
                my_val = my_ln(x, eps);
                std_val = std::log(1.0 + x);
            }
        }
        // Вывод результата
        if (!valid_point) {
            std::cout << std::setw(10) << x << " | " 
                      << "ОШИБКА: x должен быть в (-1; 1]" << "\n";
        } else {
            double diff = std::abs(my_val - std_val);
            std::cout << std::setw(10) << x << " | " 
                      << std::setw(12) << my_val << " | " 
                      << std::setw(12) << std_val << " | " 
                      << std::setw(12) << diff << "\n";
        }
    }
    std::cout << std::string(65, '-') << "\n";

    return 0;
}