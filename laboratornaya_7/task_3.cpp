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
            matrix[i][j] = 1 + std::rand() % 100; // от 1 до 100
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }
    // Сортировка каждого столбца по убыванию (сортировка пузырьком)
    for (int j = 0; j < SIZE; j++) { // Проходим по каждому столбцу
        for (int i = 0; i < SIZE - 1; i++) { // Внешний цикл сортировки
            for (int k = 0; k < SIZE - 1 - i; k++) { // Внутренний цикл
                if (matrix[k][j] < matrix[k + 1][j]) {
                    // Меняем местами, если верхний элемент меньше нижнего
                    int temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }

    // Вывод отсортированной матрицы
    std::cout << "\nМатрица со столбцами, отсортированными по убыванию:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}