#pragma once
#include <stdexcept>                  
#include "node.h"

/// <summary>
/// Шаблонная структура односвязного циклического списка CycleList.
/// </summary>
/// <typeparam name="T">Тип данных, которые хранятся в списке.</typeparam>
template <typename T>
class CycleList
{
private:
    Node<T>* tail = nullptr;            // Указатель на конец списка
    int size = 0;                       // Количество элементов в списке

public:
    /// <summary> Деструктор: вызывает метод clear() </summary>
    ~CycleList()
    {
        clear();                     // Очищаем список при удалении объекта
    }

    /// <summary> Добавление элемента в конец списка </summary>
    /// <param name="value">Значение для добавления</param>
    void add(T value)
    {
        Node<T>* newNode = new Node<T>(value); // Создаём новый узел с заданным значением

        if (!tail)                        // Если список пустой (tail == nullptr)
        {                      
            tail = newNode;               // Новый элемент
            newNode->next = tail;         // Циклическая связь: сам на себя
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;          
        }

        size++;                           // Увеличиваем размер списка
    }

/// </summary>
/// <param name="index">Индекс вставки (0 ≤ index ≤ size)</param>
/// <param name="value">Значение для вставки</param>
/// <exception cref="std::out_of_range">Выбрасывается, если индекс вне диапазона.</exception>
    void insert(int index, T value)
    {
        if (index < 0 || index > size)                  // Проверка на допустимость индекса
            throw std::out_of_range("Invalid index");   // Если индекс недопустим — исключение

        Node<T>* newNode = new Node<T>(value);          // Создаём новый узел

        if (!tail)
        {
            // Список пуст — добавляем первый элемент
            tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            Node<T>* prev = tail;

            if (index != 0)
            {
                prev = tail->next;
                for (int i = 0; i < index - 1; i++)
                    prev = prev->next;
            }

            newNode->next = prev->next;
            prev->next = newNode;

            if (index == size)
                tail = newNode;
        }

        size++;
    }


    /// <summary> Удаление элемента по индексу </summary>
    void removeAt(int index)
    {
        if (!tail || index < 0 || index >= size)
            throw std::out_of_range("Invalid index");

        Node<T>* toDelete = nullptr;

        if (size == 1)
        {
            toDelete = tail;
            tail = nullptr;
        }
        else if (index == 0)
        {
            toDelete = tail->next;
            tail->next = toDelete->next;
        }
        else
        {
            Node<T>* prev = tail->next;
            for (int i = 0; i < index - 1; i++)
                prev = prev->next;

            toDelete = prev->next;
            prev->next = toDelete->next;

            if (toDelete == tail)
                tail = prev;
        }

        delete toDelete;
        size--;
    }

    /// <summary> Получение ссылки на элемент по индексу </summary>
    T& operator[](const int index) const
    {
        if (index < 0 || index >= size)                     // Проверка индекса
            throw std::out_of_range("Invalid index");

        Node<T>* current = tail->next;                      // Начинаем с головы
        for (int i = 0; i < index; i++)                     // Доходим до нужного индекса
            current = current->next;

        return current->data;                               // Возвращаем данные
    }

    /// <summary> Получение количества элементов </summary>
    int count() const
    {
        return size;                                        // Просто возвращаем размер
    }

    /// <summary> Подсчёт количества вхождений значения </summary>
    int count(T value) const
    {
        if (!tail) return 0;                                // Если список пуст — 0

        int counter = 0;                                    // Счётчик вхождений
        Node<T>* current = tail->next;

        for (int i = 0; i < size; i++)
        {                                                   // Проходим по всем узлам
            if (current->data == value) 
                counter++;                                  // Если данные совпадают — +1
            current = current->next;                        // Переход к следующему
        }

        return counter;                                     // Возвращаем результат
    }

    /// <summary> Полная очистка списка </summary>
    void clear()
    {
        while (size > 0)
        {                                                         // Пока есть элементы
            removeAt(0);                                    // Удаляем первый
        }
        tail = nullptr;
    }
};
