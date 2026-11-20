#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    const int SIZE = 5;
    int matrix[SIZE][SIZE];
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    // Заполнение и вывод исходной матрицы
    std::cout << "Исходная матрица 5x5:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = 10 + std::rand() % 90; // от 10 до 99
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }

    // Замена элементов выше главной диагонали на 0
    // Условие "выше диагонали" - это когда индекс столбца больше индекса строки (j > i)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j > i) {
                matrix[i][j] = 0;
            }
        }
    }

    // Вывод измененной матрицы
    std::cout << "\nМатрица после замены (выше диагонали - нули):\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}