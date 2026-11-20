#include <iostream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    const int SIZE = 15; // Размер массива
    int arr[SIZE];
    int zeroCount = 0;   // Счетчик нулей
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    // Заполнение массива числами от 0 до 100
    std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 101; // Остаток от деления на 101 дает диапазон 0..100
        std::cout << arr[i] << " ";
        
        // Проверка на ноль
        if (arr[i] == 0) {
            zeroCount++;
        }
    }

    std::cout << "\n\nКоличество нулевых элементов: " << zeroCount << std::endl;

    return 0;
}