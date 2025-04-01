#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	int numberForEnter;
	Stack<int> stack;

	cout << "Введите число: ";
	while (cin >> numberForEnter && numberForEnter !=0)
	{
		cout << "Введите число: ";
		stack.push(numberForEnter);	
	}

	while (stack.count()) 
	{
		int number = stack.pop();
		if (number > 0)
		{
			cout << "Числа: " << number << endl;
		}
	}
}
