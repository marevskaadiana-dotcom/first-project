#define NOMINMAX
#include <iostream>
#include <string>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::string text;
    std::cout << "Введите строку (или просто нажмите Enter): ";
    // Используем getline, чтобы считать всю строку, включая пробелы, или зафиксировать пустой ввод (если пользователь просто нажал Enter)
    std::getline(std::cin, text);
    // Метод empty() возвращает true, если строка пустая, и false в противном случае
    if (text.empty()) {
        std::cout << "Результат: Введенная строка ПУСТАЯ.\n";
    } else {
        std::cout << "Результат: Строка НЕ пустая. Вы ввели: \"" << text << "\"\n";
    }

    return 0;
}