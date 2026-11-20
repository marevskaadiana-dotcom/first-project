#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    const int SIZE = 3;
    int matrix[SIZE][SIZE];
    int trace = 0;
    std::cout << "Введите элементы матрицы 3x3:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }

    // Вычисление следа матрицы (сумма элементов главной диагонали)
    for (int i = 0; i < SIZE; i++) {
        trace += matrix[i][i];
    }

    std::cout << "\nСлед матрицы (сумма главной диагонали) = " << trace << std::endl;

    return 0;
}