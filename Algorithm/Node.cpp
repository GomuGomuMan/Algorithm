#include "Node.h"

AnyList::AnyList()
{
	first = NULL;
	count = 0;
}



void AnyList::insertFront(int newData)
{
	Node * newNode = new Node;

	newNode->setData(newData);
	newNode->setLink(first);

	if (first == NULL || count == 0)
	{
		first = newNode;
		first->setLink(NULL);
	}

	else
	{
		newNode->setLink(first);
		first = newNode;
	}

	++count;
}



void AnyList::insertBack(int newData)
{
	if (first == NULL || count == 0)
		insertFront(newData);

	else
	{
		Node * newNode = new Node;

		newNode->setData(newData);
		newNode->setLink(NULL);

		Node * temp = first;

		// Traverse
		while (temp->getLink() != NULL)
			temp = temp->getLink();

		temp->setLink(newNode);
	}

	++count;
}



void AnyList::insertPos(int pos, int val)
{

}



void AnyList::deleteNode(int)
{

}

void AnyList::print() const
{

}

void AnyList::destroyList()
{

}

AnyList::~AnyList()
{

}