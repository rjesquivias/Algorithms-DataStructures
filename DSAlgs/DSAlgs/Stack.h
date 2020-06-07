#pragma once

// Average          worst              worst space complexity
//                                     O(n)
// Access:    Θ(n)  Access:    O(n)
// Search:    Θ(n)	Search:    O(n)
// Insertion: Θ(1)  Insertion: O(1)
// Deletion:  Θ(1)  Deletion:  O(1)

class Stack
{
public:
	Stack() {}

	virtual bool empty() = 0;

	virtual int size() = 0;

	virtual void push(int) = 0;

	virtual void pop() = 0;

	virtual int top() = 0;

};