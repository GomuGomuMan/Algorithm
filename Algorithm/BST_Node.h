#pragma once

template <typename T>
struct BST_Node
{
	int key;
	BST_Node<T> * left;
	BST_Node<T> * right;

	// Destructor
	~BST_Node()
	{
		delete left;
		delete right;
	}
};