#define NOMINMAX
#include <iostream>
#include <Windows.h>

// Прототип функции
// const int arr[] - массив, который нельзя изменить внутри функции
// int size - количество элементов в массиве
void printArray(const int arr[], int size);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    const int SIZE = 10;
    int myArray[SIZE] = {5, 12, 8, 34, 1, 99, 23, 45, 7, 0};
    std::cout << "Вывод массива через функцию:\n";
    std::cout << "[ ";
    
    // Вызов функции
    // Передаем имя массива (это указатель на первый элемент) и его размер
    printArray(myArray, SIZE);
    
    std::cout << "]\n";

    return 0;
}

// Определение функции
void printArray(const int arr[], int size) {
    // Проходим по всем элементам массива от 0 до size - 1
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        
        // Выводим запятую и пробел, если это не последний элемент
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
}