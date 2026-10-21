#pragma once
#include <string>

class Task
{
    private:
        std::string title;      // Название задачи
        bool isCompleted;       // Статус выполнения
    public:
        // Конструктор: принимает название и статус
        Task(std::string t, bool isCompleted = false);

        // Геттеры - это методы для получения данных
        // const после метода означает, что метод не изменяет объект
        std::string getTitle() const;
        bool isCompleted() const;

        // Методы изменения состояния
        void markAsCompleted();

        // Сериализация: преобразования объекта в строку для сохранения в файл
        std::string serialize() const;

        // Десериализация: создание объекта из строки
        // static - метод принадлежит классу, а не объекту
        static Task deserealize(const std::string& data);

        // Вывод задачи на экран
        void display(int index) const;
};