#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double temperature;
    while (true) { //Ввод температуры
        std::cout << "Введите температуру: ";
        if (std::cin >> temperature) {
            break;
        }
        std::cout << "ОШИБКА! Введите число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (temperature < 0) { //условие
        std::cout << "Мороз\n";
    } else {
        std::cout << "Тепло\n";
    }

    return 0;
}