#pragma once

// Average          worst              worst space complexity
//                                     O(n)
// Access:    Θ(n)  Access:    O(n)
// Search:    Θ(n)	Search:    O(n)
// Insertion: Θ(1)  Insertion: O(1)
// Deletion:  Θ(1)  Deletion:  O(1)

class Queue
{
public:
	Queue() {}

	virtual bool empty() = 0;

	virtual int size() = 0;
	
	virtual void enqueue(int x) = 0;

	virtual int dequeue() = 0;

	virtual int front() = 0;

	virtual int back() = 0;

};