#include <iostream>
#include <stack.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	int numberForEnter;
	Stack<int> stack;

	while (cin >> numberForEnter && numberForEnter != 0)
	{
		stack.push(numberForEnter);
		
	}

	while (stack.count() > 0) 
	{
		int number = stack.pop();
		if (number > 0)
		{
			cout << "Числа: " << number << endl;
		}
	}
}
