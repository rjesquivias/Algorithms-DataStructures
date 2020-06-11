#pragma once
#include "Stack.h"
#include "DoublyLinkedList.h"

class LinkedStack : public Stack
{
public:
	LinkedStack()
	{
		
	}

	LinkedStack(const LinkedStack& other)
	{
		this->_data = other._data;
	}

	virtual ~LinkedStack()
	{
		
	}

	void operator=(const LinkedStack& other)
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

	virtual void push(int x)
	{
		this->_data.push_back(x);
	}

	virtual void pop()
	{
		this->_data.pop_back();
	}

	virtual int top()
	{
		return this->_data.back();
	}

private:
	DoublyLinkedList _data;
};