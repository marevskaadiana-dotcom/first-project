#define NOMINMAX
#include <iostream>
#include <string>
#include <cctype>   // Для функций isalpha, tolower и др.
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::string text;
    std::cout << "Введите строку для проверки: ";
    // Считываем всю строку, включая пробелы
    std::getline(std::cin, text);
    bool found = false;
    // Если строка пустая или состоит из 1 символа, соседей нет
    if (text.length() < 2) {
        std::cout << "Строка слишком короткая для поиска соседних символов.\n";
        return 0;
    }

    // Проходим по строке до предпоследнего символа, чтобы не выйти за границы
    for (size_t i = 0; i < text.length() - 1; i++) {
        // Используем <cctype>: приводим символы к нижнему регистру для сравнения
        // static_cast<unsigned char> защищает от ошибок с кириллицей
        char current = static_cast<char>(std::tolower(static_cast<unsigned char>(text[i])));
        char next = static_cast<char>(std::tolower(static_cast<unsigned char>(text[i + 1])));
        // Сравниваем приведенные символы
        if (current == next) {
            std::cout << "Найдены одинаковые соседние символы: '" 
                      << text[i] << "' и '" << text[i + 1] 
                      << "' (на позициях " << i << " и " << i + 1 << ")\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Одинаковых соседних символов не найдено.\n";
    }

    return 0;
}