#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    const int SIZE = 15; // Размер массива
    int arr[SIZE];
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    // Заполнение и вывод исходного массива
    std::cout << "Исходный массив:          ";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 101; 
        std::cout << arr[i] << " ";
    }

    // Вывод в обратном порядке
    std::cout << "\nМассив в обратном порядке: ";
    for (int i = SIZE - 1; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
    return 0;
}