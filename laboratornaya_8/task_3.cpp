#define NOMINMAX
#include <iostream>
#include <string>
#include <algorithm> // Для std::reverse
#include <limits>    // Для очистки буфера
#include <Windows.h> 

// Функция для вывода меню
void printMenu() {
    std::cout << "\nТекстовый редактор\n";
    std::cout << "1. Ввести новую строку\n";
    std::cout << "2. Вывести текущую строку\n";
    std::cout << "3. Реверс строки (перевернуть)\n";
    std::cout << "4. Заменить подстроку\n";
    std::cout << "5. Вставить подстроку по индексу\n";
    std::cout << "6. Удалить часть строки\n";
    std::cout << "7. Выход\n";
    std::cout << "Выберите действие (1-7): ";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::string text = ""; // Наша текущая строка
    int choice;

    while (true) {
        printMenu();
        
        // Защита ввода для выбора пункта меню
        while (!(std::cin >> choice)) {
            std::cout << "ОШИБКА! Введите число от 1 до 7: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        // Очищаем буфер после cin >> choice,чтобы getline не считал остаток строки как пустой ввод
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "Введите новую строку: ";
                std::getline(std::cin, text);
                std::cout << "Строка успешно обновлена!\n";
                break;
            }
            case 2: {
                std::cout << "Текущая строка: [" << text << "]\n";
                break;
            }
            case 3: {
                std::reverse(text.begin(), text.end());
                std::cout << "Строка перевернута.\n";
                break;
            }
            case 4: {
                if (text.empty()) {
                    std::cout << "Строка пуста. Нечего заменять.\n";
                    break;
                }
                std::string oldSub, newSub;
                std::cout << "Что заменить? Введите подстроку: ";
                std::getline(std::cin, oldSub);
                std::cout << "На что заменить? Введите новую подстроку: ";
                std::getline(std::cin, newSub);

                size_t pos = text.find(oldSub);
                if (pos == std::string::npos) {
                    std::cout << "Подстрока не найдена!\n";
                } else {
                    // Заменяем ВСЕ вхождения
                    while (pos != std::string::npos) {
                        text.replace(pos, oldSub.length(), newSub);
                        pos = text.find(oldSub, pos + newSub.length()); // Ищем дальше
                    }
                    std::cout << "Замена выполнена.\n";
                }
                break;
            }
            case 5: {
                int index;
                std::string sub;
                std::cout << "Введите индекс для вставки (от 0 до " << text.length() << "): ";
                std::cin >> index;
                
                if (index < 0 || index > text.length()) {
                    std::cout << "ОШИБКА: Неверный индекс!\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                
                std::cout << "Введите подстроку для вставки: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, sub);
                
                text.insert(index, sub);
                std::cout << "Вставка выполнена.\n";
                break;
            }
            case 6: {
                int index, count;
                std::cout << "Введите индекс начала удаления: ";
                std::cin >> index;
                std::cout << "Сколько символов удалить? ";
                std::cin >> count;
                
                if (index < 0 || index >= text.length() || count <= 0) {
                    std::cout << "ОШИБКА: Неверные параметры удаления!\n";
                } else {
                    text.erase(index, count); // Удаляем count символов начиная с index
                    std::cout << "Удаление выполнено.\n";
                }
                break;
            }
            case 7: {
                std::cout << "Выход из редактора. До свидания!\n";
                return 0;
            }
            default: {
                std::cout << "Неверный выбор! Введите число от 1 до 7.\n";
                break;
            }
        }
    }
    return 0;
}