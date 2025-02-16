#include <iostream>
#include <stack.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	int n=4;
	Stack <int> T;
	while (n != 0) {
		cout << "Введите число: ";
		cin >> n;
		T.push(n);
	}
	while (T.count()) {
		if (T.peek() > 0)
		{
			cout << "Числа: " << T.peek() << endl;
		}
		T.pop();
	}
}
