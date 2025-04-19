#pragma once
#include "node.h"

/// <summary>
/// Класс Stack реализует стек с использованием связного списка.
/// Стек работает по принципу "последний пришел — первый вышел" (LIFO).
/// </summary>
template <typename T>
class Stack
{
private:
   
    Node<T>* top = nullptr; // Указатель на вершину стека.
    int counter = 0;     // Количество элементов в стеке.

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
        top = new Node<T>(value, top);
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
        Node<T>* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        counter--;
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
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        counter = 0;
    }
};
