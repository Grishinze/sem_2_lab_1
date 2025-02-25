#pragma once

/// <summary>
/// Класс Stack реализует стек с использованием связного списка.
/// Стек работает по принципу "последний пришел — первый вышел" (LIFO).
/// </summary>
template <typename T>
class Stack
{
private:
    /// <summary>
    /// Внутренняя структура, представляющая узел стека.
    /// </summary>
    struct Node
    {
        T data; // Данные, хранящиеся в узле.
        Node* next; // Указатель на следующий узел в стеке.
    };

    Node* top = nullptr; // Указатель на вершину стека.
    int counter = 0; // Количество элементов в стеке.

public:
    /// <summary>
    /// Деструктор, очищает стек и освобождает память.
    /// </summary>
    ~Stack()
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент в стек.
    /// </summary>
    /// <param name="value">Значение, которое нужно добавить в стек.</param>
    void push(T value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        ++counter;
    }

    /// <summary>
    /// Удаляет верхний элемент из стека и возвращает его значение.
    /// </summary>
    /// <returns>Значение верхнего элемента стека.</returns>
    /// <exception cref="std::runtime_error">Выбрасывается, если стек пуст.</exception>
    T pop()
    {
        if (top == nullptr)
        {
            throw "Stack is empty";
        }
        Node* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        --counter;
        return value;
    }

    /// <summary>
    /// Возвращает значение верхнего элемента стека без его удаления.
    /// </summary>
    /// <returns>Значение верхнего элемента стека.</returns>
    /// <exception cref="std::runtime_error">Выбрасывается, если стек пуст.</exception>
    T peek()
    {
        if (top == nullptr)
        {
            throw "Stack is empty";
        }
        return top->data;
    }

    /// <summary>
    /// Возвращает текущее количество элементов в стеке.
    /// </summary>
    /// <returns>Количество элементов в стеке.</returns>
    int count()
    {
        return counter;
    }

    /// <summary>
    /// Очищает стек, удаляя все элементы.
    /// </summary>
    void clear()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        counter = 0;
    }
};
