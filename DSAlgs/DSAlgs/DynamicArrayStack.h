#pragma once
#include "Stack.h"
#include "DynamicArray.h"

class DynamicArrayStack : public Stack
{
public:
	DynamicArrayStack()
	{
	}

	DynamicArrayStack(const DynamicArrayStack& other)
	{
		this->_data = other._data;
	}

	virtual ~DynamicArrayStack()
	{
		
	}

	void operator=(const DynamicArrayStack& other)
	{
		this->_data = other._data;
	}

	virtual bool empty()
	{
		return this->_data.getSize() == 0;
	}

	virtual int size()
	{
		return this->_data.getSize();
	}

	virtual void push(int x)
	{
		this->_data.push_back(x);
	}

	virtual void pop()
	{
		if (!this->_data.empty())
			this->_data.pop_back();
	}

	virtual int top()
	{
		if (!this->_data.empty())
			return this->_data[this->_data.getSize() - 1];
		else return -1;
	}

private:
	DynamicArray _data;
};