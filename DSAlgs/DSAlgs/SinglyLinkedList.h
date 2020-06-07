#pragma once
// Average          worst              worst space complexity
//                                     O(n)
// Access:    Θ(n)  Access:    O(n)
// Search:    Θ(n)	Search:    O(n)
// Insertion: Θ(1)  Insertion: O(1)
// Deletion:  Θ(1)  Deletion:  O(1)

class Node
{
public:
	Node(int d, Node* n) : data(d), next(n) {}
	int data;
	Node* next;
};

class SinglyLinkedList
{
public:
	SinglyLinkedList()
	{
		head = nullptr;
		size = 0;
	}

	SinglyLinkedList(const SinglyLinkedList& other)
	{
		head = nullptr;
		size = 0;

		Node* temp = other.head;
		int* tempArray = new int[other.size];

		int index = 0;
		while (temp)
		{
			tempArray[index++] = temp->data;
			temp = temp->next;
		}

		for (int i = other.size - 1; i >= 0; i--)
		{
			push_front(tempArray[i]);
		}

		delete[] tempArray;
	}

	~SinglyLinkedList()
	{
		clear();
	}

	void operator=(const SinglyLinkedList& other)
	{
		clear();

		Node* temp = other.head;
		int* tempArray = new int[other.size];

		int index = 0;
		while (temp)
		{
			tempArray[index++] = temp->data;
			temp = temp->next;
		}

		for (int i = other.size - 1; i >= 0; i--)
		{
			push_front(tempArray[i]);
		}

		delete[] tempArray;
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	bool empty()
	{
		return size == 0;
	}

	void push_front(int element)
	{
		Node* newNode = new Node(element, head);
		head = newNode;
		size++;
	}

	void pop_front()
	{
		if (!empty())
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			size--;
		}
	}

	int front()
	{
		return empty() ? -1 : head->data;
	}

	int back()
	{
		if (empty()) return -1;

		Node* temp = head;
		while (temp->next)
			temp = temp->next;

		return temp->data;
	}

	void insertAt(int element, int index)
	{
		if (index >= 0 && index <= size)
		{
			if (index == 0)
			{
				push_front(element);
			}
			else
			{
				Node* sentinal = nullptr;
				Node* actual = head;
				int counter = 0;

				while (actual && counter < index)
				{
					sentinal = actual;
					actual = actual->next;
					counter++;
				}

				if(sentinal)
					sentinal->next = new Node(element, actual);

				size++;
			}
		}
	}

	void remove(int index)
	{
		if (index >= 0 && index <= size)
		{
			if (index == 0)
			{
				pop_front();
			}
			else
			{
				Node* sentinal = nullptr;
				Node* actual = head;
				int counter = 0;

				while (actual && counter < index)
				{
					sentinal = actual;
					actual = actual->next;
					counter++;
				}
				
				if (sentinal && actual)
					sentinal->next = actual->next;

				delete actual;

				size--;
			}		
		}
	}

	Node* search(int key)
	{
		Node* iter = head;
		while (iter && iter->data != key)
			iter = iter->next;

		return iter;
	}

	int getSize()
	{
		return size;
	}

private:
	Node* head;
	int size;
};