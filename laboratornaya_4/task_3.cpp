#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <limits>
#include <string>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::string regLogin = "", regPass = "";
    std::string login, pass;
    int mainChoice, subChoice;
    while (true) {
        std::cout << "ГЛАВНОЕ МЕНЮ (НЕ АВТОРИЗОВАН)\n";
        std::cout << "1 - Регистрация\n";
        std::cout << "2 - Вход\n";
        std::cout << "3 - Выход из программы\n";
        std::cout << "Выберите действие: ";
        // Защита ввода 
        while (!(std::cin >> mainChoice)) {
            std::cout << "ОШИБКА! Введите число (1-3): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        //ВНЕШНИЙ SWITCH
        switch (mainChoice) {
            case 1: {
                std::cout << "РЕГИСТРАЦИЯ\n";
                std::cout << "Придумайте логин: ";
                std::cin >> regLogin;
                std::cout << "Придумайте пароль: ";
                std::cin >> regPass;
                std::cout << "Успешно зарегистрировано!\n";
                break;
            }
            case 2: {
                if (regLogin.empty()) {
                    std::cout << "\nОШИБКА: Сначала пройдите регистрацию!\n";
                    break;
                }
                bool isLoggedIn = false;
                int attempts = 3;
                std::cout << "ВХОД В СИСТЕМУ\n";
                while (attempts > 0) {
                    std::cout << "Логин: ";
                    std::cin >> login;
                    std::cout << "Пароль: ";
                    std::cin >> pass;
                    if (login == regLogin && pass == regPass) {
                        isLoggedIn = true;
                        break;
                    } else {
                        attempts--;
                        std::cout << "Неверный логин или пароль. Осталось попыток: " << attempts << "\n";
                    }
                }

                if (isLoggedIn) {
                    std::cout << "\nУспешный вход! Добро пожаловать.\n";
                    bool inAccount = true;
                    while (inAccount) {
                        std::cout << "ЛИЧНЫЙ КАБИНЕТ\n";
                        std::cout << "1 - Калькулятор\n";
                        std::cout << "2 - Конвертер температур\n";
                        std::cout << "3 - Пройти тест\n";
                        std::cout << "4 - Выход из аккаунта\n";
                        std::cout << "Выберите функцию: ";
                        // Защита ввода
                        while (!(std::cin >> subChoice)) {
                            std::cout << "ОШИБКА! Введите число (1-4): ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }

                        //ВНУТРЕННИЙ (ВЛОЖЕННЫЙ) SWITCH
                        switch (subChoice) {
                            case 1: {
                                std::cout << "КАЛЬКУЛЯТОР\n";
                                double a, b;
                                char op;
                                std::cout << "Введите выражение (например, 5 + 3): ";
                                while (!(std::cin >> a >> op >> b)) {
                                    std::cout << "ОШИБКА! Неверный формат. Введите (число операция число): ";
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                if (op == '+') std::cout << "Результат: " << a + b << "\n";
                                else if (op == '-') std::cout << "Результат: " << a - b << "\n";
                                else if (op == '*') std::cout << "Результат: " << a * b << "\n";
                                else if (op == '/') {
                                    if (b == 0) std::cout << "ОШИБКА: Деление на ноль!\n";
                                    else std::cout << "Результат: " << a / b << "\n";
                                }
                                else std::cout << "ОШИБКА: Неизвестная операция.\n";
                                break;
                            }
                            case 2: {
                                std::cout << "КОНВЕРТЕР\n";
                                std::cout << "1. °C -> °F\n";
                                std::cout << "2. °F -> °C\n";
                                int convChoice;
                                std::cout << "Выбор: ";
                                while (!(std::cin >> convChoice)) {
                                    std::cout << "ОШИБКА! Введите 1 или 2: ";
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                double temp;
                                std::cout << "Введите температуру: ";
                                while (!(std::cin >> temp)) {
                                    std::cout << "ОШИБКА! Введите число: ";
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                if (convChoice == 1) std::cout << "Результат: " << (temp * 9.0 / 5.0 + 32.0) << " °F\n";
                                else if (convChoice == 2) std::cout << "Результат: " << ((temp - 32.0) * 5.0 / 9.0) << " °C\n";
                                else std::cout << "Неверный выбор конвертации.\n";
                                break;
                            }
                            case 3: {
                                std::cout << "ТЕСТ\n";
                                std::cout << "Сколько будет 7 * 8? ";
                                int answer;
                                while (!(std::cin >> answer)) {
                                    std::cout << "ОШИБКА! Введите число: ";
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                if (answer == 56) std::cout << "Правильно! Отличная работа.\n";
                                else std::cout << "Неправильно. Правильный ответ: 56.\n";
                                break;
                            }
                            case 4: {
                                std::cout << "Выход из аккаунта\n";
                                inAccount = false;
                                break;
                            }
                            default: {
                                std::cout << "Неверный выбор. Введите число от 1 до 4.\n";
                                break;
                            }
                        }
                    }
                } else {
                    std::cout << "\nВы исчерпали все 3 попытки. Возврат в главное меню.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Завершение работы программы. До свидания!\n";
                return 0;
            }
            default: {
                std::cout << "Неверный выбор. Введите число от 1 до 3.\n";
                break;
            }
        }
    }
    return 0;
}