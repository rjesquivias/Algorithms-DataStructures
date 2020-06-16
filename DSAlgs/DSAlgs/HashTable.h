#pragma once
#include "SymbolTable.h"
#include <list>
#include <vector>

// Average          worst              worst space complexity
//                                     O(n)
// Access:    N/A   Access:    N/A
// Search:    Θ(1)	Search:    O(n)
// Insertion: Θ(1)  Insertion: O(1)
// Deletion:  Θ(1)  Deletion:  O(n)

class HashTable : public SymbolTable
{
public:

	HashTable() : t(m, std::list<int>())
	{
	}

	virtual int search(int key)
	{
		auto& l = t[hash(key, m)];
		for (auto it = l.begin(); it != l.end(); it++)
		{
			if (*it == key) return key;
		}

		return -1;
	}

	virtual void insert(int key)
	{
		auto& l = t[hash(key, m)];
		l.push_back(key);
	}

	virtual void remove(int key)
	{
		auto& l = t[hash(key, m)];
		for (auto it = l.begin(); it != l.end(); it++)
		{
			if (*it == key)
			{
				l.erase(it);
				return;
			}
		}
	}

	int hash(int key, int m)
	{
		return abs(key) % m;
	}

private:
	// Default value for hash table size
	// See CLRS 11.3.1 The division method
	const int m = 701;
	std::vector<std::list<int>> t;
};