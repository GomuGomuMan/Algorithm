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

// Delete Node
template <typename T>
void BST<T>::delete_node(T key)
{
	delete_node_p(key, root);
}

template <typename T>
BST_Node<T> * BST<T>::delete_node_p(T key, BST_Node<T> * node)
{
	if (!root)
	{
		return root;
	}
		
	else if (key < node->key)
		node->left = delete_node_p(key, node->left);
	else if (key > node->key)
		node->right = delete_node_p(key, node->right);
	else
	{
		// Case 1: No child
		if (!node->left && !node->right)
		{
			delete node;
			node = nullptr;
		}
		//Case 2: 1 child
		else if (!node->left)
		{
			BST_Node<T> * temp = node;
			node = node->right;
			delete temp;
			temp = nullptr;
		}
		else if (!node->right)
		{
			BST_Node<T> * temp = node;
			node = node->left;
			delete temp;
			temp = nullptr;
		}
		// Case 3: 2 children
		else
		{
			BST_Node<T> * temp = find_min(node->right);
			node->key = temp->key;
			node->right = delete_node_p(temp->key, node->right);
		}
		
	}

	return node;
}

// find_min
template <typename T>
BST_Node<T> * BST<T>::find_min(BST_Node<T> * node) const
{
	BST_Node<T> * current = node;

	while (current->left)
		current = current->left;

	return current;
}

/// Test
// Delete
template <typename T>
void BST<T>::test_delete() 
{
	insert(50);
	insert(30);
	insert(70);
	insert(20);
	insert(40);
	insert(60);
	insert(80);
	print_inorder();
	std::cout << "Hello World" << std::endl;
	delete_node(70);
	delete_node(50);
	delete_node(20);
	print_inorder();
}