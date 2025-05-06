#pragma once
#include <stdexcept>

/// <summary>
/// Узел двусвязного списка.
/// </summary>
/// <typeparam name="T">Тип данных, хранимый в узле.</typeparam>
template <typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;

    /// <summary>
    /// Конструктор узла.
    /// </summary>
    /// <param name="value">Значение, сохраняемое в узле.</param>
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

/// <summary>
/// Шаблонная структура двусвязного списка List.
/// </summary>
/// <typeparam name="T">Тип элементов в списке.</typeparam>
template <typename T>
class List
{
private:
    Node<T>* head = nullptr;  // Первый элемент
    Node<T>* tail = nullptr;  // Последний элемент
    int size = 0;             // Текущее количество элементов

public:
    /// <summary>
    /// Деструктор. Вызывает очистку списка.
    /// </summary>
    ~List()
    {
        clear();
    }

    /// <summary>
    /// Добавление элемента в конец списка.
    /// </summary>
    /// <param name="value">Значение для добавления.</param>
    void add(T value)
    {
        Node<T>* node = new Node<T>(value);

        if (!tail)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        size++;
    }

    /// <summary>
    /// Вставка элемента в заданную позицию.
    /// </summary>
    /// <param name="index">Позиция вставки (индексация от 0).</param>
    /// <param name="value">Вставляемое значение.</param>
    /// <exception cref="std::out_of_range">Если индекс вне диапазона.</exception>
    void insert(int index, T value)
    {
        if (index < 0 || index > size)
            throw std::out_of_range("Invalid index");

        Node<T>* node = new Node<T>(value);

        if (index == size)
        {
            add(value);
            delete node; // node уже добавлен внутри add
            return;
        }

        if (index == 0)
        {
            node->next = head;
            if (head) head->prev = node;
            head = node;
            if (!tail) tail = node;
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index; i++)
                current = current->next;

            node->next = current;
            node->prev = current->prev;

            if (current->prev)
                current->prev->next = node;

            current->prev = node;
        }

        size++;
    }

    /// <summary>
    /// Удаление элемента по индексу.
    /// </summary>
    /// <param name="index">Индекс элемента для удаления.</param>
    /// <exception cref="std::out_of_range">Если индекс вне диапазона.</exception>
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Invalid index");

        Node<T>* toDelete = head;

        for (int i = 0; i < index; i++)
            toDelete = toDelete->next;

        if (toDelete->prev)
            toDelete->prev->next = toDelete->next;
        else
            head = toDelete->next;

        if (toDelete->next)
            toDelete->next->prev = toDelete->prev;
        else
            tail = toDelete->prev;

        delete toDelete;
        size--;
    }

    /// <summary>
    /// Доступ к элементу по индексу.
    /// </summary>
    /// <param name="index">Индекс (начиная с 0).</param>
    /// <returns>Ссылка на элемент.</returns>
    /// <exception cref="std::out_of_range">Если индекс вне диапазона.</exception>
    T& operator[](const int index) const
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Invalid index");

        Node<T>* current = head;
        for (int i = 0; i < index; i++)
            current = current->next;

        return current->data;
    }

    /// <summary>
    /// Возвращает количество элементов в списке.
    /// </summary>
    /// <returns>Число элементов.</returns>
    int count() const
    {
        return size;
    }

    /// <summary>
    /// Подсчёт числа вхождений значения.
    /// </summary>
    /// <param name="value">Искомое значение.</param>
    /// <returns>Количество вхождений в список.</returns>
    int count(T value) const
    {
        int occurrences = 0;
        Node<T>* current = head;

        while (current)
        {
            if (current->data == value)
                occurrences++;
            current = current->next;
        }

        return occurrences;
    }

    /// <summary>
    /// Удаляет все элементы списка.
    /// </summary>
    void clear()
    {
        while (head)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        size = 0;
    }
};
