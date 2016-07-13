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



void AnyList::insertPos(int pos, int newData)
{
	if ((first == NULL || count == 0) && pos > 1)
	{
		std::cerr << "List is Empty! Proceed to insert the first element" << std::endl;
		insertFront(newData);
	}

	else if (pos > count)
	{
		std::cerr << "Position is larger than List's size (" + count << "). Please specify a position that is less than the List's size";
		insertPos(pos, newData);
	}

	else
	{
		Node * newNode = new Node;

		newNode->setData(newData);

		Node * beforeNew = first;

		// Traverse
		int i = 0;

		// Find node before pos
		while (beforeNew->getLink() != NULL && i < pos - 1)
		{
			beforeNew = beforeNew->getLink();
			++i;
		}

		// Find node after pos
		Node * afterNew = beforeNew->getLink();

		beforeNew->setLink(newNode);
		newNode->setLink(afterNew);

		++count;
	}
		
}



void AnyList::deleteNode(int)
{

}

void AnyList::print() const
{
	if (first == NULL || count == 0)
		std::cout << "List is empty! " << std::endl;

	else
	{
		Node * temp = first;
		// Traverse
		std::cout << "List: " << temp->getData();
		temp = temp->getLink();
		
		while (temp->getLink() != NULL)
		{
			std::cout << ", " << temp->getData();
			temp = temp->getLink();
		}
		std::cout << std::endl;
		std::cout << "Size: " << count << std::endl;
	}
}

void AnyList::destroyList()
{

}

AnyList::~AnyList()
{

}