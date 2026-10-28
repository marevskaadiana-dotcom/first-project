#include <iostream>
#include <Windows.h>
#include <limits>
#include <iomanip>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int choice;
    double temp, result;
    std::cout << "Конвертер температур\n";
    std::cout << "1 — °C → °F\n";
    std::cout << "2 — °F → °C\n";
    std::cout << "3 — °C → K\n";
    std::cout << "4 — K → °C\n";
    std::cout << "5 — °F → K\n";
    std::cout << "6 — K → °F\n";
    std::cout << "7 — Показать формулы\n";
    std::cout << "8 — Проверка: возможна ли температура?\n";
    std::cout << "9 — Выход\n";
// Ввод выбора с защитой
    while (true) {
        std::cout << "Выберите вариант (1-9): ";
        if (std::cin >> choice) {
            if (choice >= 1 && choice <= 9) break;
            std::cout << "ОШИБКА! Введите число от 1 до 9.\n";
        } else {
            std::cout << "ОШИБКА! Введите именно число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    switch (choice) {
        case 1: {
            std::cout << "Введите температуру в °C: ";
            std::cin >> temp;
            result = temp * 9.0 / 5.0 + 32.0;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << temp << " °C = " << result << " °F\n";
            break;
        }
        case 2: {
            std::cout << "Введите температуру в °F: ";
            std::cin >> temp;
            result = (temp - 32.0) * 5.0 / 9.0;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << temp << " °F = " << result << " °C\n";
            break;
        }
        case 3: {
            std::cout << "Введите температуру в °C: ";
            std::cin >> temp;
            if (temp < -273.15) {
                std::cout << "Температура ниже абсолютного нуля!\n";
                break;
            }
            result = temp + 273.15;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << temp << " °C = " << result << " K\n";
            break;
        }
        case 4: {
            std::cout << "Введите температуру в K: ";
            std::cin >> temp;
            if (temp < 0) {
                std::cout << "Температура не может быть отрицательной в шкале Кельвина!\n";
                break;
            }
            result = temp - 273.15;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << temp << " K = " << result << " °C\n";
            break;
        } 
        case 5: {
            std::cout << "Введите температуру в °F: ";
            std::cin >> temp;
            double c = (temp - 32.0) * 5.0 / 9.0;
            if (c < -273.15) {
                std::cout << "Температура ниже абсолютного нуля!\n";
                break;
            }
            result = c + 273.15;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << temp << " °F = " << result << " K\n";
            break;
        }
        case 6: {
            std::cout << "Введите температуру в K: ";
            std::cin >> temp;
            if (temp < 0) {
                std::cout << "Температура не может быть отрицательной в шкале Кельвина!\n";
                break;
            }
            double c = temp - 273.15;
            result = c * 9.0 / 5.0 + 32.0;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << temp << " K = " << result << " °F\n";
            break;
        }
        case 7: {
            std::cout << "Формулы:\n";
            std::cout << "°C → °F: F = C * 9/5 + 32\n";
            std::cout << "°F → °C: C = (F - 32) * 5/9\n";
            std::cout << "°C → K: K = C + 273.15\n";
            std::cout << "K → °C: C = K - 273.15\n";
            break;
        }
        case 8: {
            std::cout << "Введите значение температуры и укажите шкалу (C/F/K): ";
            char scale;
            std::cin >> temp >> scale;
            bool possible = true;
            switch (scale) {
                case 'C': case 'c':
                    if (temp < -273.15) possible = false;
                    break;
                case 'F': case 'f':
                    if (temp < -459.67) possible = false;
                    break;
                case 'K': case 'k':
                    if (temp < 0) possible = false;
                    break;
                default:
                    possible = false;
            }
            std::cout << (possible ? "Температура возможна." : "Температура физически невозможна.") << "\n";
            break;
        }
        case 9: {
            std::cout << "Выход из программы.\n";
            return 0;
        }

        default: {
            std::cout << "Неверный выбор! Пожалуйста, введите число от 0 до 9.\n";
            break;
        }
    }

    return 0;
}