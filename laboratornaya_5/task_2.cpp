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
    // Ввод начала интервала
    while (true) {
        std::cout << "Введите начало интервала: ";
        if (std::cin >> first) break;
        std::cout << "ОШИБКА! Введите число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Ввод конца интервала
    while (true) {
        std::cout << "Введите конец интервала: ";
        if (std::cin >> last) break;
        std::cout << "ОШИБКА! Введите число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Ввод шага
    while (true) {
        std::cout << "Введите шаг интервала: ";
        if (std::cin >> shag) break;
        std::cout << "ОШИБКА! Введите число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Проверка корректности интервала и шага
    if (first > last) {
        std::cout << "ОШИБКА: начало интервала не может быть больше конца!" << std::endl;
        return 1;
    }
    if (shag <= 0) {
        std::cout << "ОШИБКА: шаг не может быть отрицательным или равным нулю!" << std::endl;
        return 1;
    }
    // Переменные для анализа
    double sum = 0.0;
    double sumSq = 0.0; // Сумма квадратов (для отклонения)
    double minY = std::numeric_limits<double>::max();
    double maxY = -std::numeric_limits<double>::max();
    int count = 0;
    std::cout << "\n$========================================$" << std::endl;
    std::cout << "    x    |   y = sin(x)/x   " << std::endl;
    std::cout << "$========================================$" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    for (double x = first; x <= last + 1e-9; x += shag) {
        double y;
        // Защита от деления на ноль: если x очень близок к 0, предел равен 1
        if (std::abs(x) < 1e-9) {
            y = 1.0;
        } else {
            y = std::sin(x) / x;
        }
        // Вывод текущего значения (используем \t для табуляции)
        std::cout << std::setw(9) << x << "\t|\t" << std::setw(9) << y << std::endl;
        // Обновление статистики
        if (count == 0) {
            minY = y;
            maxY = y;
        } else {
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }
        sum += y;
        sumSq += y * y;
        count++;
    }
    // Дополнительный анализ
    if (count > 0) {
        double mean = sum / count;
        // Среднее квадратическое отклонение (упрощённо): 
        // Вычисляем дисперсию как (Среднее квадратов - Квадрат среднего)
        double variance = (sumSq / count) - (mean * mean);
        if (variance < 0) variance = 0; // Защита от микроскопической погрешности double
        double rmsd = std::sqrt(variance);
        std::cout << "\n--- Результаты анализа ---" << std::endl;
        std::cout << "Количество точек:   " << count << std::endl;
        std::cout << "Сумма значений:     " << sum << std::endl;
        std::cout << "Минимальное (min):  " << minY << std::endl;
        std::cout << "Максимальное (max): " << maxY << std::endl;
        std::cout << "Среднее значение:   " << mean << std::endl;
        std::cout << "Среднее квадратическое отклонение: " << rmsd << std::endl;
    } else {
        std::cout << "Не удалось собрать данные для анализа." << std::endl;
    }

    return 0;
}