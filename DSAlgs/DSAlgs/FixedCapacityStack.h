#pragma once
#include "Stack.h"

class FixedCapacityStack : public Stack
{
public:
	FixedCapacityStack(int capacity)
	{
		this->_capacity = capacity;
		this->_size = 0;
		this->_data = new int[capacity];
		for (int i = 0; i < this->_capacity; i++)
			this->_data[i] = 0;
	}

	FixedCapacityStack(const FixedCapacityStack& other)
	{
		this->_capacity = other._capacity;
		this->_size = other._size;
		this->_data = new int[this->_capacity];
		for (int i = 0; i < this->_capacity; i++)
			this->_data[i] = other._data[i];
	}

	virtual ~FixedCapacityStack()
	{
		delete[] this->_data;
	}

	void operator=(const FixedCapacityStack& other)
	{
		if (this->_data)
			delete[] this->_data;

		this->_capacity = other._capacity;
		this->_size = other._size;
		this->_data = new int[this->_capacity];
		for (int i = 0; i < this->_capacity; i++)
			this->_data[i] = other._data[i];
	}

	virtual bool empty()
	{
		return this->size() == 0;
	}

	virtual int size()
	{
		return this->_size;
	}

	virtual void push(int x)
	{
		if(this->_size < this->_capacity)
			this->_data[this->_size++] = x;
	}

	virtual void pop()
	{
		if (!this->empty())
		{
			this->_size--;
		}
	}

	virtual int top()
	{
		return this->empty() ? -1 : this->_data[this->_size - 1];
	}

	int capacity()
	{
		return this->_capacity;
	}

private:
	int* _data;
	int _size;
	int _capacity;
};