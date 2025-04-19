#pragma once

/// <summary>
/// Шаблонная очередь Queue<T>, реализованная на основе односвязного списка.
/// Поддерживает базовые операции FIFO: добавление, извлечение, подсчёт и очистку.
/// </summary>
/// <typeparam name="T">Тип данных, хранимых в очереди.</typeparam>
template <typename T>
class Queue
{
private:

    /// <summary>
    /// Узел очереди, содержащий значение и указатель на следующий элемент.
    /// </summary>
    struct Node
    {
        T data;         // Значение, хранящееся в узле.
        Node* next;     // Указатель на следующий узел.

        /// <summary>
        /// Конструктор узла.
        /// </summary>
        /// <param name="data">Значение, которое хранится в узле.</param>
        /// <param name="next">Указатель на следующий узел (по умолчанию nullptr).</param>
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head = nullptr; // Указатель на начало очереди.
    Node* tail = nullptr; // Указатель на конец очереди.
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
        Node* temp = new Node(value);
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

        Node* temp = head;
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
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        counter = 0;
    }
};
