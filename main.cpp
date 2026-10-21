#include "TaskManager.h"
#include <iostream>
#include <limits>

// Очистка буфера ввода (чтобы избежать залипания при некорректном вводе)
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// Получение строки от пользователя
std::string getUserInput(const std::string& prompt)
{
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}
// Получение числового выбора от пользователя
int getUserChoice()
{
    int choice;
    while (true)
    {
        std::cout << "Ваш выбор: ";

        // Пытаемся прочитать число
        if (std::cin >> choice)
        {
            clearInputBuffer();
            return choice;
        }

        // Если ввод некорректный
        std::cout << "Ошибка! Введите число!\n";
        clearInputBuffer();
    }
}

int main() 
{
    // Создаем менеджер задач
    TaskManager manager;
    int choice = 0;

    // Главный цикл программы
    while (choice != 5)
    {
        std::cout << "\n ---- TaskManager ----\n";
        std::cout << "1. Показать задачи\n";
        std::cout << "2. Добавить задачу\n";
        std::cout << "3. Отметить задачу выполенной\n";
        std::cout << "4. Удалить задачу\n";
        std::cout << "5. Выход\n";

        choice = getUserChoice();

        // Обработка выбора пользователя
        switch (choice)
        {
            case 1:
            {
                manager.displayTasks();
                break;
            }
            case 2:
            {
                std::string title = getUserInput("Введите название задачи:");
                if (!title.empty())
                {
                    manager.addTask(title);
                    break;
                }
            }
            case 3:
            {
                manager.displayTasks();
                std::cout << "Введите номер задачи для выполнения:";
                int compIdx;
                std::cin >> compIdx;
                clearInputBuffer();
                manager.completedTask(compIdx);
                break;
            }
            case 4:
            {
                manager.displayTasks();
                std::cout << "Введите номер задачи для удаления: ";
                int delIdx;
                std::cin >> delIdx;
                clearInputBuffer();
                manager.deleteTask(delIdx);
                break;
            }
            case 5:
            {
                std::cout << "Сохранение данных и выход...\n";
                break;
            }
            default:
            {
                std::cout << "Неизвестная команда. Попробуйте снова";
            }
        }
    }
    // Деструктор manager автоматически вызовется в этот месте и сохранит данные
    return 0;
}
