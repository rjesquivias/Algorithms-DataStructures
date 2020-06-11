#pragma once
#include "Queue.h"
#include "DoublyLinkedList.h"

class LinkedQueue : public Queue
{
public:
	LinkedQueue()
	{
		
	}

	LinkedQueue(const LinkedQueue& other)
	{
		this->_data = other._data;
	}

	~LinkedQueue()
	{
		
	}

	void operator=(const LinkedQueue& other)
	{
		this->_data = other._data;
	}

	virtual bool empty()
	{
		return this->_data.empty();
	}

	virtual int size()
	{
		return this->_data.getSize();
	}

	virtual void enqueue(int x)
	{
		this->_data.push_back(x);
	}

	virtual int dequeue()
	{
		int sol = this->_data.front();
		this->_data.pop_front();
		return sol;
	}

	virtual int front()
	{
		return this->_data.front();
	}

	virtual int back()
	{
		return this->_data.back();
	}


private:
	DoublyLinkedList _data;
};