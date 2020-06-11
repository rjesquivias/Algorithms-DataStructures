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
	Node(int d, Node* n, Node* p) : data(d), next(n), prev(p) {}
	int data;
	Node* next;
	Node* prev;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList()
	{
		head = new Node(0, nullptr, nullptr);
		tail = new Node(0, nullptr, head);
		head->next = tail;
		size = 0;
	}

	DoublyLinkedList(const DoublyLinkedList& other)
	{
		head = new Node(0, nullptr, nullptr);
		tail = new Node(0, nullptr, head);
		head->next = tail;
		size = 0;

		Node* temp = other.head->next;
		while (temp && temp != other.tail)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}

	~DoublyLinkedList()
	{
		clear();
		delete head;
		delete tail;
	}

	void operator=(const DoublyLinkedList& other)
	{
		clear();

		Node* temp = other.head->next;
		while (temp != other.tail)
		{
			push_back(temp->data);
			temp = temp->next;
		}
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
		Node* newNode = new Node(element, head->next, nullptr);
		head->next->prev = newNode;
		head->next = newNode;
		size++;
	}

	void push_back(int element)
	{
		if (this->empty())
		{
			Node* newNode = new Node(element, tail, head);
			head->next = newNode;
			tail->prev = newNode;
		}
		else
		{
			Node* newNode = new Node(element, tail, tail->prev);
			tail->prev->next = newNode;
			tail->prev = newNode;
		}

		size++;
	}

	void pop_front()
	{
		if (!empty())
		{
			Node* temp = head->next;
			head->next = temp->next;
			temp->next->prev = head;

			delete temp;
			size--;
		}
	}

	void pop_back()
	{
		if (!empty())
		{
			Node* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;

			delete temp;
			size--;
		}
	}

	int front()
	{
		return empty() ? -1 : head->next->data;
	}

	int back()
	{
		if (empty()) return -1;

		return tail->prev->data;
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
				Node* actual = head->next;
				int counter = 0;

				while (actual != tail && counter < index)
				{
					sentinal = actual;
					actual = actual->next;
					counter++;
				}

				if (sentinal && sentinal != tail)
				{
					sentinal->next = new Node(element, actual, sentinal);
					actual->prev = sentinal->next;
				}

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
				Node* temp = this->head->next;
				while (index > 0 && temp && temp != tail)
				{
					temp = temp->next;
					index--;
				}

				if (index == 0 && temp && temp != tail)
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete temp;
				}

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
	Node* tail;
	int size;
};