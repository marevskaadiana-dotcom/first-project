#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int quadrant;
    //Ввод номера четверти с защитой от ошибок
    while (true) {
        std::cout << "Введите номер координатной четверти (1-4): ";
        if (std::cin >> quadrant) {
            break;
        }
        std::cout << "ОШИБКА! Введите целое число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    //Простой switch без группировки
    switch (quadrant) {
        case 1:
            std::cout << "Знаки координат: (+, +)\n";
            break;
        case 2:
            std::cout << "Знаки координат: (+, -)\n";
            break;
        case 3:
            std::cout << "Знаки координат: (-, -)\n";
            break;
        case 4:
            std::cout << "Знаки координат: (-, +)\n";
            break;
        default:
            std::cout << "ОШИБКА: Четвертей всего 4. Введите число от 1 до 4.\n";
            break;
    }

    return 0;
}