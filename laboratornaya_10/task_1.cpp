#define NOMINMAX
#include <iostream>
#include <Windows.h>

// Прототип функции
// Знак & означает, что мы передаем переменные по ссылке (по адресу), а не копируем их
void swap(char& a, char& b);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char char1, char2;
    std::cout << "Введите первый символ: ";
    std::cin >> char1;
    std::cout << "Введите второй символ: ";
    std::cin >> char2;
    // Вывод до обмена
    std::cout << "\nДо обмена:\n";
    std::cout << "char1 = " << char1 << "\n";
    std::cout << "char2 = " << char2 << "\n";

    // Вызов функции
    // Передаем сами переменные, а не их значения
    swap(char1, char2);
    // Вывод после обмена
    std::cout << "\nПосле обмена:\n";
    std::cout << "char1 = " << char1 << "\n";
    std::cout << "char2 = " << char2 << "\n";

    return 0;
}

// Определение фуекции
void swap(char& a, char& b) {
    // Временная переменная для сохранения значения 'a'
    char temp = a; 
    a = b;         // в 'a' кладем значение 'b'
    b = temp;      // в 'b' кладем сохраненное значение 'a'
}