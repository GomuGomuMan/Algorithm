#pragma once
#include <iostream>
#include <string>


class Node
{
public:
	Node() {};
	Node(int theData, Node * theLink)
		: data(theData), link(theLink) {}
	Node* getLink() const { return link; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setLink(Node *theLink) { link = theLink; }
	~Node() { std::cout << "Node destructor is called here!" << std::endl; }



private:
	int data;
	Node * link;
};



//class Node
//{
//public:
//	Node() {}
//	Node(int theData, Node *previousData, Node *nextData)
//		:data(theData), previous(previousData), next(nextData) {}
//	Node *getNextLink() const { return next; }
//	Node *getPreviousLink() const { return previous; }
//	int getData() const { return data; }
//	void setData(int theData) { data = theData; }
//	void setNextLink(Node * pointer) { next = pointer; }
//	void setPreviousLink(Node * pointer) { previous = pointer; }
//
//private:
//	int data;
//	Node *previous;
//	Node *next;
//};



class AnyList
{
public:
	// Default Constructor
	AnyList();

	void insertFront(const int);

	void insertBack(const int);

	/*
		returns 0 if successful
		returns 1 if fails
	*/
	int insertPos(const int pos, const int val);

	void swap(const int pos1, const int pos2);

	void deleteNode(const int);

	void print() const;

	~AnyList();

private:
	Node * first;
	int count;
};