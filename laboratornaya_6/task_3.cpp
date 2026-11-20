#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    const int SIZE = 25; 
    int arr[SIZE];
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    // Заполнение массива от -100 до 100
    // Формула: min + rand() % (max - min + 1)
    std::cout << "Сгенерированный массив:\n";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = -100 + std::rand() % 201; 
        std::cout << arr[i] << " ";
    }
    std::cout << "\n Локальные экстремумы \n";
    // Поиск экстремумов (начинаем с 1-го индекса и до SIZE-2, так как у крайних нет двух соседей)
    bool found = false;
    for (int i = 1; i < SIZE - 1; i++) {
        // Проверка на локальный максимум
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            std::cout << "Пик (максимум) на индексе " << i << ": " << arr[i] << "\n";
            found = true;
        }
        // Проверка на локальный минимум
        else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            std::cout << "Впадина (минимум) на индексе " << i << ": " << arr[i] << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "В данном массиве локальных экстремумов нет.\n";
    }

    return 0;
}