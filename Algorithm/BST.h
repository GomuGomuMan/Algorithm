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

		// Destructor
		/*~BST() { delete root; }*/
		~BST() { delete root; }

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

		// Delete tree
		void delete_bst(BST_Node<T> * node);

		BST_Node<T> * root;
};

//#include "BST.cpp"