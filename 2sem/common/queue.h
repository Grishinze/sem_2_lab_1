#pragma once


template <typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;

	};
	Node* tope = nullptr;
	int counter = 0;

	
public:
	~Queue()
	{
		clear();
	}

	int count()
	{
		return counter;
	}



};
