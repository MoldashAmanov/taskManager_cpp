#include "TaskManager.h"
#include <fstream>
#include <iostream>

// Конструктор: загружаем задачи из файла
TaskManager::TaskManager(const std::string& fname) : filename(fname)
{
    loadFromFile();
}
// Деструктор: сохраняем задачи в файл
TaskManager::~TaskManager()
{
    saveToFile();
}
// Загрузка задач из файла
void TaskManager::loadFromFile()
{
    std::ifstream file(filename);

    // Проверяем, открылся ли файл
    if (file.is_open())
    {
        std::string line;

        // Читаем файл построчно
        while (std::getline(file, line))
        {
            if (!line.empty())
            {
                // Десериализуем строку в объект Task
                tasks.push_back(Task::deserialize(line));
            }
        }
        file.close();
    }
    // Если файла нет - норм, просто начинаем с пустым списком
}
// Сохранение задач в файл
void TaskManager::saveToFile() const
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        // Проходим по всем задачам и сериализуем их
        for (const auto& task: tasks)
        {
            file << task.serialize() << "\n";
        }
        file.close();
    }
}
// Добавление новой задачи
void TaskManager::addTask(const std::string& title)
{
    tasks.push_back(Task(title));
    std::cout << "Задача добавлена!\n";
}
// Отображение всех задач
void TaskManager::displayTasks() const
{
    if (tasks.empty())
    {
        std::cout << "Список задач пуст\n";
        return;
    }

    std::cout << "\n --- Ваши задачи ---\n";

    // Проходим по всем задачам с индексацией
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        tasks[i].display(i + 1);
    }
    std::cout << "--------------------\n\n";
}
// Отметить задачу как выполненную
void TaskManager::completedTask(int index)
{
    // Проверяем корректность индекса 
    if (index >= 1 && index <= static_cast<int>(tasks.size()))
    {
        tasks[index - 1].markAsCompleted();
    
        std::cout << "Задача отмечена как выполненная\n";
    } 
    else
    {
        std::cout << "Неверный номер задачи!\n";
    }
}
// Удаление задачи
void TaskManager::deleteTask(int index)
{
    if (index >= 1 && index <= static_cast<int>(tasks.size()))
    {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Задача удалена!\n";
    }
    else
    {
        std::cout << "Неверный номер задачи!\n";
    }
}