#pragma once

/// <summary>
/// ��������� ������� Queue<T>, ������������� �� ������ ������������ ������.
/// ������������ ������� �������� FIFO: ����������, ����������, ������� � �������.
/// </summary>
/// <typeparam name="T">��� ������, �������� � �������.</typeparam>
template <typename T>
class Queue
{
private:

    /// <summary>
    /// ���� �������, ���������� �������� � ��������� �� ��������� �������.
    /// </summary>
    struct Node
    {
        T data;         // ��������, ���������� � ����.
        Node* next;     // ��������� �� ��������� ����.

        /// <summary>
        /// ����������� ����.
        /// </summary>
        /// <param name="data">��������, ������� �������� � ����.</param>
        /// <param name="next">��������� �� ��������� ���� (�� ��������� nullptr).</param>
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head = nullptr; // ��������� �� ������ �������.
    Node* tail = nullptr; // ��������� �� ����� �������.
    int counter = 0;      // ������� ���������� ��������� � �������.

public:

    /// <summary>
    /// ���������� �������. ����������� ��� ���������� ������.
    /// </summary>
    ~Queue()
    {
        clear();
    }

    /// <summary>
    /// ��������� ������� � ����� �������.
    /// </summary>
    /// <param name="value">��������, ������� ����� ��������.</param>
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
    /// ��������� ������� �� ������ �������.
    /// </summary>
    /// <returns>��������, ������� ���� � ������ �������.</returns>
    /// <exception cref="std::out_of_range">���������, ���� ������� �����.</exception>
    T unqueue()
    {
        if (head == nullptr)
        {
            throw std::out_of_range("������� �����");
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
    /// ���������� ���������� ��������� � �������.
    /// </summary>
    /// <returns>���������� ���������.</returns>
    int count()
    {
        return counter;
    }

    /// <summary>
    /// ��������� ������� �������, ������ ��� ��������.
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
