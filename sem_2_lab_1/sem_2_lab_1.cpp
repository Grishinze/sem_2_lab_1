#include <iostream>
using namespace std;

template<typename T>
struct stack
{
	T* arr;
	int cap;
	int top;

	stack() {
		cap = 10;
		arr = new T[cap];
		top = -1;
	}

	~stack() {
		delete[] arr;
	}

	void push(T num) {
		if (top + 1 == cap)
		{
			int newCap = cap * 2;
			T* newArr = new T[newCap];
			for (int i = 0; i < cap; i++)
			{
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			cap = newCap;
				
		}
		arr[++top] = num;
	}

	T pop() {
		return arr[top--];
	}

	T peek() {
		return arr[top];
	}

	void clear() {
		top = -1;
	}

	int count() {
		return top + 1;
	}
};


int main()
{
	stack<int> myStack;
	int num;

	while (cin >> num && num != 0) {
		myStack.push(num);
	}

	while (myStack.count() > 0) {
		int value = myStack.pop();
		if (value > 0) {
			cout << value << " ";
		}
	}
	
}


