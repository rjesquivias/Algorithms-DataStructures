#pragma once
#include <stdexcept>

class DynamicArray
{
public:
	DynamicArray()
	{
		size = 0;
		capacity = 10;
		data = new int[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = 0;
	}

	DynamicArray(const DynamicArray& other)
	{
		size = other.size;
		capacity = other.capacity;
		data = new int[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = other.data[i];
	}

	virtual ~DynamicArray()
	{
		clear();
	}

	void operator=(const DynamicArray& other)
	{
		if (data)
			delete[] data;

		size = other.size;
		capacity = other.capacity;
		data = new int[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = other.data[i];
	}

	void push_back(int element)
	{
		data[size++] = element;
		if (size >= capacity)
		{
			resize(capacity * 2);
		}
	}

	void pop_back()
	{
		if (!empty())
		{
			if (size-- < capacity / 4)
			{
				resize(capacity / 2);
			}
		}
	}
	
	int& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else throw std::out_of_range("Index is not within bounds");
	}

	bool empty()
	{
		return size == 0;
	}

	int getSize()
	{
		return size;
	}

	int getCapacity()
	{
		return capacity;
	}

	void resize(int n)
	{
		int* temp = new int[n];
		for (int i = 0; i < n; i++)
			temp[i] = 0;

		for (int i = 0; i < size; i++)
			temp[i] = data[i];

		delete[] data;

		data = temp;
		capacity = n;
	}

	void clear()
	{
		while (!empty())
			pop_back();
	}

private:

	int* data;
	int size;
	int capacity;
};