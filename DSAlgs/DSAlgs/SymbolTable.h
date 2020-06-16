#pragma once

// Key == value
class SymbolTable
{
public:

	virtual int search(int key) = 0;

	virtual void insert(int key) = 0;

	virtual void remove(int key) = 0;
};