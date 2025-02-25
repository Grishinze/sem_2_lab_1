#include <iostream>
#include <stack.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	int numberForEnter=4;
	Stack<int> stack;

	while (numberForEnter != 0)
	{
		cout << "Введите число: ";
		cin >> numberForEnter;
		if (numberForEnter != 0)
		{
			stack.push(numberForEnter);
		}
	}

	while (stack.count()) {
		int number = stack.pop();
		if (number > 0)
		{
			cout << "Числа: " << stack.peek() << endl;
		}
	}
}
