#pragma once
#include "SymbolTable.h"
#include <algorithm>

class AVLTree : SymbolTable
{
public:

	AVLTree()
	{
		root = nullptr;
	}

	virtual int search(int key)
	{
		if (contains(key)) return key;
		else return -1;
	}

	virtual void insert(int key)
	{
		insertA(key);
	}

	virtual void remove(int key)
	{
		removeA(key);
	}

	// The height of a rooted tree is the number of edges between the tree's
	// root and its furthest leaf. This means that a tree containing a single
	// node has a height of 0
	int height()
	{
		if (root == nullptr) return 0;
		return root->height;
	}

	// Returns the number of nodes in the tree
	int size()
	{
		return nodeCount;
	}

	// Returns whether or not the tree is empty
	bool isEmpty()
	{
		return size() == 0;
	}

private:

	class Node
	{
	public:
		// 'bf' is short for Balance Factor
		int bf;

		// The value/data contained within the node
		int value;

		// The height of this node in the tree
		int height;

		// The left and right children of this node
		Node* left, * right;

		Node(int bf, int value, int height, Node* left, Node* right)
		{
			this->bf = bf;
			this->value = value;
			this->height = height;
			this->left = left;
			this->right = right;
		}

		Node(int value) : Node(0, value, 0, nullptr, nullptr)
		{
		}
	};

	Node* root;

	// Tracks the number of nodes inside the tree
	int nodeCount = 0;

	// Returns true/false depending on whether a value exists in the tree
	bool contains(int value)
	{
		return contains(root, value);
	}

	// Recursive contains helper method
	bool contains(Node* root, int value)
	{
		if (!root) return false;
		if (value < root->value) return contains(root->left, value);
		else if (value > root->value) return contains(root->right, value);
		else return true;
	}

	// Insert/add a value to the AVL tree. The value must not be null, O(log(n))
	bool insertA(int value)
	{
		if (!contains(root, value))
		{
			root = insert(root, value);
			nodeCount++;
			return true;
		}

		return false;
	}

	bool removeA(int elem)
	{
		if (contains(root, elem))
		{
			root = remove(root, elem);
			nodeCount--;
			return true;
		}

		return false;
	}

	// Inserts a value inside the AVL tree
	Node* insert(Node* node, int value)
	{
		// Base case
		if (node == nullptr) return new Node(value);

		// Insert node in left subtree
		if (value < node->value) node->left = insert(node->left, value);

		// Insert nod ein right subtree
		else node->right = insert(node->right, value);

		// Update balance factor and height values
		update(node);

		return balance(node);
	
	}

	// Update a node's height and balance factor
	void update(Node* node)
	{
		int leftNodeHeight = (node->left == nullptr) ? -1 : node->left->height;
		int rightNodeHeight = (node->right == nullptr) ? -1 : node->right->height;

		// Update this node's height
		node->height = 1 + std::max(leftNodeHeight, rightNodeHeight);

		// Update balance factor
		node->bf = rightNodeHeight - leftNodeHeight;
	}

	// Re-balance a node if its balance factor is +2 or -2
	Node* balance(Node* node)
	{
		// Left heavy subtree
		if (node->bf == -2)
		{
			// Left-Left case
			if (node->left->bf <= 0)
				return leftLeftCase(node);
			// Left-Right case
			else
				return leftRightCase(node);
		}
		// Right heavy subtree needs balancing
		else if (node->bf == +2)
		{
			// Right-Right case
			if (node->right->bf >= 0)
				return rightRightCase(node);
			// Right-Left case
			else
				return rightLeftCase(node);
		}

		// Node either has a balance factor of 0, +1 or -1 which is fine
		return node;
	}

	Node* leftLeftCase(Node* node)
	{
		return rightRotation(node);
	}
	
	Node* leftRightCase(Node* node)
	{
		node->left = leftRotation(node->left);
		return leftLeftCase(node);
	}

	Node* rightRightCase(Node* node)
	{
		return leftRotation(node);
	}

	Node* rightLeftCase(Node* node)
	{
		node->right = rightRotation(node->right);
		return rightRightCase(node);
	}

	Node* leftRotation(Node* node)
	{
		Node* newParent = node->right;
		node->right = newParent->left;
		newParent->left = node;
		update(node);
		update(newParent);
		return newParent;
	}

	Node* rightRotation(Node* node)
	{
		Node* newParent = node->left;
		node->left = newParent->right;
		newParent->right = node;
		update(node);
		update(newParent);
		return newParent;
	}

	Node* remove(Node* node, int elem)
	{
		if (node == nullptr) return nullptr;

		if (elem < node->value) node->left = remove(node->left, elem);
		else if (elem > node->value) node->right = remove(node->right, elem);
		// Found the node we wish to remove
		else
		{
			// This is the case with only a right subtree or no subtree at all.
			// In this situation just swap the node we wish to remove
			// with its right child
			if (node->left == nullptr) return node->right;

			// This is the case with only a left subtree or 
			// no subtree at all. In this situation just
			// swap the node we wish to remove with its left child.
			else if (node->right == nullptr) return node->left;

			// When removing a node from a binary tree with two links the
			// successor of the node being removed can either be the largest
			// value in the left subtree or the smallest value in the right
			// subtree. As a heuristic, I will remove from the subtree with
			// the most nodes in hopes that this may help with balancing
			else
			{
				// Chose to remove from left subtree
				if (node->left->height > node->right->height)
				{
					// Swap the value of the successor into the node
					int successorValue = findMax(node->left);
					node->value = successorValue;

					// Find the largest node in the left subtree
					node->left = remove(node->left, successorValue);
				}
				else
				{
					// Swap the value of the successor into the node
					int successorValue = findMin(node->right);
					node->value = successorValue;

					// Find the largest node in the left subtree
					node->right = remove(node->right, successorValue);
				}
			}
		}

		// Update balance factor and height values
		update(node);

		// Re-balance tree
		return balance(node);
	}

	int findMin(Node* node)
	{
		while (node->left != nullptr) node = node->left;
		return node->value;
	}

	int findMax(Node* node)
	{
		while (node->right != nullptr) node = node->right;
		return node->value;
	}

};