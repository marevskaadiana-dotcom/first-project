#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>

// Прототиа функции
// totalSeconds передается по значению
// hours, minutes, seconds передаются по ссылке
void secondsToHMS(int totalSeconds, int& hours, int& minutes, int& seconds);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int total, h = 0, m = 0, s = 0;
    // Ввод общего количества секунд с защитой от ошибок
    std::cout << "Введите общее количество секунд: ";
    while (!(std::cin >> total) || total < 0) {
        std::cout << "ОШИБКА! Введите положительное целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Вызов функции
    secondsToHMS(total, h, m, s);

    // Вывод результата
    std::cout << "\nРезультат:\n";
    std::cout << "Часов:   " << h << "\n";
    std::cout << "Минут:   " << m << "\n";
    std::cout << "Секунд:  " << s << "\n";
    std::cout << "Время:   " 
              << (h < 10 ? "0" : "") << h << ":" 
              << (m < 10 ? "0" : "") << m << ":" 
              << (s < 10 ? "0" : "") << s << "\n";

    return 0;
}

// Определение функции
void secondsToHMS(int totalSeconds, int& hours, int& minutes, int& seconds) {
    // 1 час = 3600 секунд
    hours = totalSeconds / 3600;
    
    // Берем остаток секунд после выделения часов
    int remainingSeconds = totalSeconds % 3600;
    
    // 1 минута = 60 секунд
    minutes = remainingSeconds / 60;
    
    // То, что осталось после выделения минут — это итоговые секунды
    seconds = remainingSeconds % 60;
}