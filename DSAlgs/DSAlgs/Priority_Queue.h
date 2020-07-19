#pragma once
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class priority_queue
{
public:
	priority_queue()
	{

	}

	priority_queue(const std::vector<int>& v)
	{
		// Place all elements in heap
		for (int i = 0; i < v.size(); i++)
		{
			heap.push_back(v[i]);
		}

		// Heapify process, O(n)
		for (int i = std::max(0, (int)((heap.size() / 2) - 1)); i >= 0; i--)
		{
			sink(i);
		}
	}

	bool isEmpty()
	{
		return heap.size() == 0;
	}

	void clear()
	{
		heap.clear();
	}

	int size()
	{
		return heap.size();
	}

	int peek()
	{
		if (isEmpty()) return -1;
		return heap[0];
	}

	void pop()
	{
		std::swap(heap[0], heap[heap.size() - 1]);
		heap.resize(heap.size() - 1);
		sink(0);
	}

	bool contains(int elem)
	{
		for (int i = 0; i < heap.size(); i++)
			if (heap[i] == elem) return true;
	}

	void add(int elem)
	{
		heap.push_back(elem);
		swim(heap.size() - 1);
	}

	void swim(int k)
	{
		int parent = (k - 1) / 2;
		while (k > 0 && heap[k] < heap[parent])
		{
			std::swap(heap[k], heap[parent]);
			k = parent;

			parent = (k - 1) / 2;
		}
	}

	void sink(int k)
	{
		while (true)
		{
			int left = 2 * k + 1;
			int right = 2 * k + 2;
			int smallest = left;

			if (right < heap.size() && heap[right] < heap[left]) smallest = right;

			if (left >= heap.size() || heap[k] < heap[smallest]) break;

			std::swap(heap[smallest], heap[k]);
			k = smallest;
		}
	}

	bool isMinHeap(int k)
	{
		if (k >= heap.size()) return true;
		int left = 2 * k + 1;
		int right = 2 * k + 2;

		if (left < heap.size() && heap[k] > heap[left]) return false;
		if (right < heap.size() && heap[k] > heap[right]) return false;

		return isMinHeap(left) && isMinHeap(right);
	}


private:
	std::vector<int> heap;
};