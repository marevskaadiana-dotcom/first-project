#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <limits>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double first, last, shag;
    while (true) {
        std::cout << "Введите начало интервала: ";
        if (std::cin >> first) {
            break;
        }
        // ввод числа с повтором ввода данных при ошибке
        std::cout << "ОШИБКА! Введите число заново.\n"; // ввод текста на экран
        std::cin.clear(); // сброс флага ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // очистка буфера от мусора
    }
    while (true) {
        std::cout << "Введите конец интервала: ";
        if (std::cin >> last) {
            break;
        }
        // ввод числа с повтором ввода данных при ошибке
        std::cout << "ОШИБКА! Введите число заново.\n"; // ввод текста на экран
        std::cin.clear(); // сброс флага ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // очистка буфера от мусора
    }
    while (true) {
        std::cout << "Введите шаг интервала: ";
        if (std::cin >> shag) {
            break;
        }
        // ввод числа с повтором ввода данных при ошибке
        std::cout << "ОШИБКА! Введите число заново.\n"; // ввод текста на экран
        std::cin.clear(); // сброс флага ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // очистка буфера от мусора
    }
    if (first > last) {
        std::cout << "ОШИБКА: начало интервала не может быть больше конца!" << std::endl;
        return 1;
    } // Условие для правильного построения функции
    if (shag <= 0) {
        std::cout << "ОШИБКА: шаг не может быть отрицательным!" << std::endl;
        return 1;
    }
    // Условие для правильного построения функции

    std::cout << "\n$====================================$" << std::endl;
    std::cout << " x | y = x**2 + 5 " << std::endl;
    std::cout << "$====================================$" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    for (double x = first; x <= last + 1e-9; x += shag) { // Использование + 1e-9 для учёта погрешности double
    double y = x*x + 5; // Вычисляем значение функции
    std::cout << std::setw(8) << x << "|" << std::setw(12) << y << std::endl; //Вывод элементов на расстоянии setw
    }
    std::cout << "$=====================================$" << std::endl;

return 0;
}