#pragma once

/// <summary>
/// ��������� `Node` ������������ ���� �������� ������.
/// </summary>
/// <typeparam name="T">��� ������, ���������� � ����.</typeparam>
template <typename T>
struct Node
{
    T data;           
    Node* next;       
    
    /// <summary>
    /// ����������� ��� �������� ����.
    /// </summary>
    /// <param name="data">������, ������� ����� ��������� � ����.</param>
    /// <param name="next">��������� �� ��������� ���� (�� ��������� nullptr).</param>
    Node(T data, Node* next = nullptr) : data(data), next(next) {}
};