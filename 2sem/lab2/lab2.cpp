#include <iostream>
#include "queue.h"
using namespace std;

/// <summary>
/// Вставляет число 1 перед каждым отрицательным числом в очереди.
/// </summary>
/// <param name="queue">Очередь, в которую вставляются элементы.</param>
void insertNegativeNumber(Queue<int>& queue)
{
	int temp = queue.count();
	for (int i = 0; i < temp; i++)
	{
		int tempNum = queue.unqueue();
		if (tempNum < 0)
		{
			queue.queue(1);
		}
		queue.queue(tempNum);
	}
}

/// <summary>
/// Удаляет все отрицательные числа из очереди.
/// </summary>
/// <param name="queue">Очередь, из которой удаляются элементы.</param>
void removeNegatives(Queue<int>& queue)
{
	int initialCount = queue.count();
	for (int i = 0; i < initialCount; i++)
	{
		int tempNum = queue.unqueue();
		if (tempNum >= 0)
		{
			queue.queue(tempNum);
		}
	}
}

/// <summary>
/// Подсчитывает количество вхождений заданного числа в очереди.
/// </summary>
/// <param name="queue">Очередь для анализа.</param>
/// <param name="value">Значение для подсчёта.</param>
/// <returns>Количество вхождений заданного числа.</returns>
int countOccurrences(Queue<int>& queue, int value)
{
	int counter = 0;
	for (int i = 0; i < queue.count(); i++)
	{
		int tempNum = queue.unqueue();
		if (tempNum == value)
		{
			counter++;
		}
		queue.queue(tempNum);
	}
	return counter;
}

/// <summary>
/// Выводит все элементы очереди в консоль.
/// Очередь при этом очищается.
/// </summary>
/// <param name="queue">Очередь для вывода.</param>
void out(Queue<int>& queue)
{
	int temp = queue.count();
	for (int i = 0; i < temp; i++)
	{
		int tempNum = queue.unqueue();
		cout << tempNum << endl;
	}
}

/// <summary>
/// Отображает меню пользователя.
/// </summary>
void menu()
{
	cout << endl << "1. Добавить элементы в очередь" << endl;
	cout << "2. Извлечь элементы из очереди" << endl;
	cout << "3. Кол-во элементов в очереди" << endl;
	cout << "4. Вставить 1 перед каждым отрицательным числом" << endl;
	cout << "5. Удалить все отрицательные числа" << endl;
	cout << "6. Подсчитать количество вхождений числа" << endl;
	cout << "7. Выйти" << endl;
	cout << "Выберите действие: " << endl;
}

/// <summary>
/// Точка входа в программу. Реализует интерфейс взаимодействия с пользователем.
/// </summary>
/// <returns>Код завершения программы.</returns>
int main()
{
	setlocale(LC_ALL, "");
	Queue<int> queue;
	int choice;
	bool running = true;

	while (running)
	{
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1: // Добавить элементы
		{
			int count, value;
			cout << endl << "Сколько элементов добавить? ";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				cout << "Введите элемент " << (i + 1) << ": ";
				cin >> value;
				queue.queue(value);
			}
			break;
		}

		case 2: // Извлечь элементы
		{
			int count;
			cout << endl << "Сколько элементов извлечь? ";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				try {
					int val = queue.unqueue();
					cout << "Извлечён: " << val << endl;
				}
				catch (const std::out_of_range& e) {
					cout << "Очередь пуста!" << endl;
					break;
				}
			}
			break;
		}

		case 3: // Кол-во элементов
		{
			cout << endl << "Количество элементов: " << queue.count() << endl;
			break;
		}

		case 4: // Вставить 1 перед каждым отрицательным числом
		{
			insertNegativeNumber(queue);
			cout << "Обновлённая очередь: " << endl;
			out(queue);
			break;
		}

		case 5: // Удалить все отрицательные числа
		{
			removeNegatives(queue);
			cout << endl << "Очередь после удаления отрицательных чисел:" << endl;
			out(queue);
			break;
		}

		case 6: // Подсчитать количество вхождений числа
		{
			int value;
			cout << endl << "Введите число для подсчёта: ";
			cin >> value;
			int result = countOccurrences(queue, value);
			cout << "Количество вхожденийc числа " << value << ": " << result << endl;
			break;
		}

		case 7: // Выйти
		{
			running = false;
			cout << endl << "Выход из программы..." << endl;
			break;
		}

		default:
			cout << "Неверный ввод. Попробуйте снова." << endl;
		}
	}
}