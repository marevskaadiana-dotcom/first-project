#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int number;
    //Ввод числа
    while (true) {
        std::cout << "Введите трёхзначное число: ";
        if (std::cin >> number) {
            break;
        }
        std::cout << "ОШИБКА! Введите целое число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    //Проверяем, является ли число трёхзначным (от 100 до 999)
    if (number < 100 || number > 999) {
        std::cout << "\nОШИБКА: Число " << number << " не является трёхзначным!\n";
    } 
    else {
        //Извлекаем цифры с помощью целочисленного деления и остатка
        int a = number / 100;         // Сотни
        int b = (number / 10) % 10;   // Десятки
        int c = number % 10;          // Единицы
        // Проверяем на палиндром: первая цифра (a) должна быть равна последней (c)
        if (a == c) {
            std::cout << "Результат: Число " << number << " ЯВЛЯЕТСЯ палиндромом.\n";
        } else {
            std::cout << "Результат: Число " << number << " НЕ является палиндромом.\n";
        }
    }

    return 0;
}