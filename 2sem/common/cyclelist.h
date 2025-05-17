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
    /// <summary>
    /// Итератор для перебора элементов списка.
    /// </summary>
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;

        Node<T>* current; // Текущий узел списка.
        int remaining;    // Количество оставшихся элементов для перебора.

        Iterator(Node<T>* start, int count)
            : current(start), remaining(count) {}

        reference operator*() const { return current->data; }
        pointer operator->() const { return &(current->data); }

        Iterator& operator++()
        {
            if (remaining > 0 && current)
            {
                current = current->next;
                --remaining;
                if (remaining == 0)
                    current = nullptr;
            }
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }
    };

    Iterator begin() const
    {
        return Iterator(tail ? tail->next : nullptr, size);
    }

    Iterator end() const
    {
        return Iterator(nullptr, 0);
    }


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
        else if (index == size)
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Iterator prev = begin();

            for (int i = 0; i < index; ++i)
            {
                ++prev;
            }

            newNode->next = prev.current->next;
            prev.current->next = newNode;

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
        else
        {
            Iterator it = begin();
            Iterator prev = it;

            for (int i = 0; i < index; ++i)
            {
                prev = it;
                ++it;
            }

            toDelete = it.current;
            prev.current->next = toDelete->next;

            if (toDelete == tail)
                tail = prev.current;
            else if (toDelete == tail->next)
                tail->next = toDelete->next;
        }

        delete toDelete;
        size--;
    }


    /// <summary> Получение ссылки на элемент по индексу </summary>
    T& operator[](const int index) const
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Invalid index");

        Iterator it = begin();
        for (int i = 0; i < index; ++i)
            ++it;

        return *it;
    }

    /// <summary> Получение количества элементов </summary>
    int count() const
    {
        return size;                                        // Просто возвращаем размер
    }

    /// <summary> Подсчёт количества вхождений значения </summary>
    int count(T value) const
    {
        int counter = 0;
        for (auto it = begin(); it != end(); ++it)
        {
            if (*it == value)
                counter++;
        }
        return counter;
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
