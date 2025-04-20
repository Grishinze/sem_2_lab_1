#pragma once

/// <summary>
/// Структура `Node` представляет узел связного списка.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в узле.</typeparam>
template <typename T>
struct Node
{
    T data;           
    Node* next;       
    
    /// <summary>
    /// Конструктор для создания узла.
    /// </summary>
    /// <param name="data">Данные, которые будут храниться в узле.</param>
    /// <param name="next">Указатель на следующий узел (по умолчанию nullptr).</param>
    Node(T data, Node* next = nullptr) : data(data), next(next) {}
};