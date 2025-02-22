#include <iostream>
#include <stack.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	int number_for_enter=4;
	Stack<int> T;

	while (number_for_enter != 0)
	{
		cout << "Введите число: ";
		cin >> number_for_enter;
		if (number_for_enter != 0)
		{
			T.push(number_for_enter);
		}
	}

	while (T.count()) {
		int number = T.pop();
		if (number > 0)
		{
			cout << "Числа: " << T.peek() << endl;
		}
	}
}
