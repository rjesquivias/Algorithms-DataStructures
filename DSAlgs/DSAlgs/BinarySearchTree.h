#pragma once
#include "SymbolTable.h"

// Average          worst              worst space complexity
//                                     O(n)
// Access:    N/A   Access:    N/A
// Search:    Θ(n)	Search:    O(n)
// Insertion: Θ(n)  Insertion: O(n)
// Deletion:  Θ(n)  Deletion:  O(n)
//
// * Special Node *
// If you can guarantee that the values that are inserted are random, the average case for all operations becomes O(lgn).
// Since we usually can't, it is linear otherwise.
// In order to guarantee worst case logarithmic performance, use a balanced tree such as a red-black tree or avl tree.

class BinarySearchTree : public SymbolTable
{
public:
	BinarySearchTree() : root(nullptr) {}

	virtual int search(int key)
	{
		Node* node = searchHelper(key, root);
		if (!node) return -1;
		else return node->data;
	}

	virtual void insert(int key)
	{
		root = insertHelper(key, root);
	}

	virtual void remove(int key)
	{
		root = removeHelper(key, root);
	}

private:
	struct Node
	{
		Node(int d, Node* l, Node* r) : data(d), left(l), right(r) {}
		int data;
		Node* left;
		Node* right;
	};

	Node* searchHelper(int key, Node* root)
	{
		if (!root) return nullptr;

		if (key == root->data) return root;
		else if (key < root->data) return searchHelper(key, root->left);
		else return searchHelper(key, root->right);
	}

	Node* insertHelper(int key, Node* root)
	{
		if (!root) return new Node(key, nullptr, nullptr);

		// Don't insert duplicate
		if (key < root->data) root->left = insertHelper(key, root->left);
		else if (key > root->data) root->right = insertHelper(key, root->right);

		return root;
	}

	Node* removeHelper(int key, Node* root)
	{
		if (!root) return nullptr;

		if (key == root->data)
		{
			if (root->left && root->right)
			{
				root->data = getLargestValue(root->left);
				removeHelper(root->data, root->left);
			}
			else if (root->left && !root->right)
			{
				Node* l = root->left;
				delete root;
				return l;
			}
			else if (!root->left && root->right)
			{
				Node* r = root->right;
				delete root;
				return r;
			}
			else // (!root->left && !root->right
			{
				delete root;
				return nullptr;
			}
		}
		else if (key < root->data) root->left = removeHelper(key, root->left);
		else root->right = removeHelper(key, root->right);

		return root;
	}

	int getLargestValue(Node* root)
	{
		if (!root) return -1;
		if (!root->right) return root->data;
		return getLargestValue(root->right);
	}

	Node* root;
};