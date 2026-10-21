#include "Task.h"
#include <string>
#include <iostream>

// Реализация конструктора
Task::Task(std::string t, bool completed) : title(t), isCompleted(completed) {}

// Реализация геттеров
std::string Task::getTitle() const 
{
    return title;
}
bool Task::getIsCompleted() const
{
    return isCompleted;
}
// Отметить задачу как выполненную
void Task::markAsCompleted()
{
    isCompleted = true;
}
// Преобразование в строку формата "название|статус"
std::string Task::serialize() const
{
    return title + "|" + (isCompleted ? "1" : "0");
}
// Создание объекта из строки
Task Task::deserialize(const std::string& data)
{
    // Находим разделитель
    size_t pos = data.find('|');

    // Извлекаем название
    std::string title = data.substr(0, pos);

    // Извлекаем статус
    bool completed = (data.substr(pos + 1) == "1");

    // Создаем и возвращаем объект
    return Task(title, completed);
}
// Вывод задачи на экран
void Task::display(int index) const
{
    std::cout << "  " << index << ". [" << (isCompleted ? "X" : " ") << "]" << title << "\n";
}