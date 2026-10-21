#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>
#include <cstdlib> // Для rand() и srand()
#include <ctime> // Для time()
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int pc[3]; // Массив для чисел компьютера
    int user[3]; // Массив для чисел игрока
    // Генерация случайных чисел от 1 до 9
    for (int i = 0; i < 3; i++) {
        pc[i] = std::rand() % 9 + 1;
    }
    std::cout << "ЛОТЕРЕЯ\n";
    std::cout << "Компьютер загадал 3 числа от 1 до 9. Попробуйте угадать!\n\n";
    // Ввод чисел пользователем
    for (int i = 0; i < 3; i++) {
        while (true) {
            std::cout << "Введите число " << (i + 1) << ": ";
            if (std::cin >> user[i]) {
                // Проверка диапазона
                if (user[i] >= 1 && user[i] <= 9) {
                    break;
                } else {
                    std::cout << "ОШИБКА! Число должно быть от 1 до 9.\n";
                }
            } else {
                std::cout << "ОШИБКА! Введите именно целое число.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    // Вывод комбинаций

    std::cout << "Загаданная комбинация: " << pc[0] << " " << pc[1] << " " << pc[2] << "\n";
    std::cout << "Ваша комбинация:       " << user[0] << " " << user[1] << " " << user[2] << "\n";
    // Подсчёт совпадений
    int exactMatches = 0;
    if (user[0] == pc[0]) exactMatches++;
    if (user[1] == pc[1]) exactMatches++;
    if (user[2] == pc[2]) exactMatches++;
    // Подсчёт совпадений в любом порядке
    int totalMatches = 0;
    bool pcUsed[3] = {false, false, false}; // Отмечаем, какие числа ПК уже совпали
    for (int i = 0; i < 3; i++) { // Проходим по числам пользователя
        for (int j = 0; j < 3; j++) { // Ищем их среди чисел ПК
            if (!pcUsed[j] && user[i] == pc[j]) {
                totalMatches++;
                pcUsed[j] = true;
                break;
            }
        }
    }
    if (exactMatches == 3) {
        std::cout << "ДЖЕКПОТ - Все 3 числа совпали и стоят на своих местах!\n";
    } 
    else if (totalMatches == 3) {
        std::cout << "СУПЕРПРИЗ - Все 3 числа совпали в любом порядке!\n";
    } 
    else if (totalMatches == 2) {
        std::cout << "ПРИЗ - Угадано 2 числа.\n";
    } 
    else if (totalMatches == 1) {
        std::cout << "Утешительный приз - Угадано 1 число.\n";
    } 
    else {
        std::cout << "Ничего не угадано. Повезет в следующий раз!\n";
    }

    return 0;
}