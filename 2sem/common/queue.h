#pragma once
#include "node.h"

/// <summary>
/// Шаблонная очередь Queue<T>, реализованная на основе односвязного списка.
/// Поддерживает базовые операции FIFO: добавление, извлечение, подсчёт и очистку.
/// </summary>
/// <typeparam name="T">Тип данных, хранимых в очереди.</typeparam>
template <typename T>
class Queue
{
private:

    Node<T>* head = nullptr; // Указатель на начало очереди.
    Node<T>* tail = nullptr; // Указатель на конец очереди.
    int counter = 0;      // Текущее количество элементов в очереди.

public:

    /// <summary>
    /// Деструктор очереди. Освобождает всю выделенную память.
    /// </summary>
    ~Queue()
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент в конец очереди.
    /// </summary>
    /// <param name="value">Значение, которое нужно добавить.</param>
    void queue(T value)
    {
        Node<T>* temp = new Node<T>(value);
        if (tail != nullptr)
        {
            tail->next = temp;
            tail = temp;
        }
        else
        {
            head = tail = temp;
        }
        counter++;
    }

    /// <summary>
    /// Извлекает элемент из начала очереди.
    /// </summary>
    /// <returns>Значение, которое было в начале очереди.</returns>
    /// <exception cref="std::out_of_range">Бросается, если очередь пуста.</exception>
    T unqueue()
    {
        if (head == nullptr)
        {
            throw std::out_of_range("Очередь пуста");
        }

        Node<T>* temp = head;
        T value = temp->data;
        head = head->next;

        delete temp;
        counter--;

        if (head == nullptr)
        {
            tail = nullptr;
        }

        return value;
    }

    /// <summary>
    /// Возвращает количество элементов в очереди.
    /// </summary>
    /// <returns>Количество элементов.</returns>
    int count()
    {
        return counter;
    }

    /// <summary>
    /// Полностью очищает очередь, удаляя все элементы.
    /// </summary>
    void clear()
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        counter = 0;
    }
};
