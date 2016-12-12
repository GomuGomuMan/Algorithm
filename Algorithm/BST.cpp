#include "BST.h"

/// BST
// Default Constructor
//template <typename T>
//BST<T>::BST()
//	: root(nullptr) { }

// Insert
template <typename T>
void BST<T>::insert(T key)
{
	if (root)
		insert_p(key, root);
	else
	{
		root = new BST_Node<T>;
		root->key = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

// insert
template <typename T>
void BST<T>::insert_p(T key, BST_Node<T> * node)
{
	if (key < node->key)
	{
		if (node->left)
			insert_p(key, node->left);
		else
		{
			node->left = new BST_Node<T>;
			node->left->key = key;
			node->left->left = nullptr;
			node->left->right = nullptr;
		}
	}
	else
	{
		if (node->right)
			insert_p(key, node->right);
		else
		{
			node->right = new BST_Node<T>;
			node->right->key = key;
			node->right->left = nullptr;
			node->right->right = nullptr;
		}
	}
}

/// Traversal
// Inorder
template <typename T>
void BST<T>::print_inorder() const
{
	print_inorder_p(root);
}

template <typename T>
void BST<T>::print_inorder_p(BST_Node<T> * node) const
{
	if (node == nullptr)
		return;
	print_inorder_p(node->left);
	std::cout << node->key << " ";
	print_inorder_p(node->right);
}

// Preorder
template <typename T>
void BST<T>::print_preorder() const
{
	print_preorder_p(root);
}

template <typename T>
void BST<T>::print_preorder_p(BST_Node<T> * node) const
{
	if (node == nullptr)
		return;
	print_preorder_p(node->left);
	std::cout << node->key << " ";
	print_preorder_p(node->right);
}

// Postorder
template <typename T>
void BST<T>::print_postorder() const
{
	print_postorder_p(root);
}

template <typename T>
void BST<T>::print_postorder_p(BST_Node<T> * node) const
{
	if (node == nullptr)
		return;
	print_postorder_p(node->left);
	std::cout << node->key << " ";
	print_postorder_p(node->right);
}

// Delete tree
template <typename T>
void BST<T>::delete_bst(BST_Node<T> * node)
{
	if (node == nullptr)
		delete root;
	else if
}
