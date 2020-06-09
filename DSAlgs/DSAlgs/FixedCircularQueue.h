#pragma once
#include "Queue.h"

class FixedCircularQueue : public Queue
{
public:
	FixedCircularQueue(int capacity)
	{
		this->_capacity = capacity;
		this->_size = 0;
		this->_head = 0;
		this->_tail = 0;
		this->_data = new int[this->_capacity];
		for (int i = 0; i < this->_capacity; i++)
			this->_data[i] = 0;
	}

	FixedCircularQueue(const FixedCircularQueue& other)
	{
		this->_capacity = other._capacity;
		this->_size = other._size;
		this->_head = other._head;
		this->_tail = other._tail;
		this->_data = new int[this->_capacity];
		for (int i = 0; i < this->_capacity; i++)
			this->_data[i] = other._data[i];
	}

	~FixedCircularQueue()
	{
		delete[] this->_data;
	}

	void operator=(const FixedCircularQueue& other)
	{
		if (this->_data) delete this->_data;

		this->_capacity = other._capacity;
		this->_size = other._size;
		this->_head = other._head;
		this->_tail = other._tail;
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

	virtual void enqueue(int x)
	{
		if (this->size() != this->_capacity)
		{
			this->_size++;
			this->_data[this->_tail++] = x;
			if (this->_tail == this->_capacity)
				this->_tail = 0;
		}
	}

	virtual int dequeue()
	{
		if (!this->empty())
		{
			this->_size--;
			int x = this->_data[this->_head++];
			if (this->_head == this->_capacity)
				this->_head = 0;
			return x;
		}
		else
			return -1;
	}

	virtual int front()
	{
		if (!this->empty())
			return this->_data[this->_head];
		else
			return -1;
	}

	virtual int back()
	{
		if (!this->empty())
		{
			int index = this->_tail - 1;
			if (index < 0) index = this->_capacity - 1;
			return this->_data[index];
		}
		else
			return -1;
	}

	int capacity()
	{
		return this->_capacity;
	}

private:
	int* _data;
	int _head;
	int _tail;
	int _size;
	int _capacity;
};