#define NOMINMAX
#include <iostream>
#include <chrono> // Для измерения времени
#include <Windows.h>
#include <string>
#include <vector>
#include <type_traits> // Для проверки типов (is_void_v)

// Тестовые функции, время которых мы измеряем

// 1. Функция без параметров и без возвращаемого значения (void)
void heavyCalculation() {
    volatile double sum = 0; // volatile запрещает компилятору удалять "ненужный" цикл
    for (int i = 0; i < 100000000; i++) {
        sum += i * 0.5;
    }
}

// 2. Функция с параметрами, возвращающая значение
long long processArray(const std::vector<int>& arr) {
    long long sum = 0;
    for (int x : arr) {
        sum += x;
    }
    return sum;
}

// Главная функция-монитор (Бенчмарк)
template <typename Func, typename... Args>
auto measureTime(Func& func, Args&... args) {
    // 1. Засекаем время старта
    auto start = std::chrono::high_resolution_clock::now();

    // 2. Проверяем на этапе компиляции: функция возвращает void?
    if constexpr (std::is_void_v<std::invoke_result_t<Func, Args...>>) {
        // Если void - просто вызываем функцию
        func(args...);
        
        // Засекаем финиш
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Время выполнения: " << elapsed.count() << " мс\n";
        // Возвращать нечего (возвращаем void)
    } 
    else {
        // Если функция возвращает значение - сохраняем его
        auto result = func(args...);
        
        // Засекаем финиш
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Время выполнения: " << elapsed.count() << " мс\n";
        
        // Возвращаем результат
        return result;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Мониторинг производительности\n\n";

    // Тест 1: Измеряем тяжелый расчет (void)
    std::cout << "1. Запуск heavyCalculation()...\n";
    measureTime(heavyCalculation); 
    std::cout << "-----------------------------------\n";

    // Тест 2: Измеряем функцию с аргументами (возвращает long long)
    std::vector<int> data(10000000, 5); // Вектор на 10 млн элементов
    
    std::cout << "2. Запуск processArray() с массивом из 10 млн элементов...\n";
    
    // Сохраняем возвращенный результат
    long long sum = measureTime(processArray, data);
    
    std::cout << "Результат суммирования: " << sum << "\n";

    return 0;
}