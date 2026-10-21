#pragma once
#include "Task.h"
#include <vector>
#include <string>

class TaskManager
{
    private:
        std::vector<Task> tasks;    // Коллекция задач
        const std::string filename; // Имя файла для сохранения

        // Приватные методы для работы с файлами
        void loadFromFile();
        void saveToFile() const;
    public:
        // Конструктор: устанавливает имя файла и загружает задачи
        TaskManager(const std::string& fname = "tasks.txt");

        // Деструктор: автоматически сохраняет задачи при уничтожении объекта (RAII принцип)
        ~TaskManager();

        // Публичные методы для управления задачами
        void addTask(const std::string& title);
        void displayTasks() const;
        void completedTask(int index);
        void deleteTask(int index);
};