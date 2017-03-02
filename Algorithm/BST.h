#pragma once


#include "BST_Node.h"

#include <iostream>


template <typename T>
class BST
{
	public:
		// Default Constructor
		BST()
			:root(nullptr) {};

		// Insert 
		void insert(T key);

		/// Traversal
		// Inorder
		void print_inorder() const;

		// Preorder
		void print_preorder() const;

		// Postorder
		void print_postorder() const;

		// Delete
		void delete_node(T key);

		// Destructor
		~BST() { delete root; }

		/// Test
		// Delete
		void test_delete();

	private:
		// Insert
		void insert_p(T key, BST_Node<T> * node);

		/// Traversal
		// Inorder
		void print_inorder_p(BST_Node<T> * node) const;

		// Preorder
		void print_preorder_p(BST_Node<T> * node) const;

		// Postorder
		void print_postorder_p(BST_Node<T> * node) const;

		// Delete node
		BST_Node<T> * delete_node_p(T key, BST_Node<T> * node);

		// find_min
		BST_Node<T> * find_min(BST_Node<T> * node) const;

		BST_Node<T> * root;
};
