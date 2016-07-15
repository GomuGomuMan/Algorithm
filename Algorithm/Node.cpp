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

		++count;
	}

	
}



int AnyList::insertPos(int pos, int newData)
{
	if ((first == NULL || count == 0) && pos != 0)
	{
		std::cerr << "List is empty. Please specify position at 0 to insert. " << std::endl;
		return 1;
	}

	else
	{
		Node * newNode = new Node;
		newNode->setData(newData);
		
		Node * beforeNew = first;

		int i = 0;
		// Traverse
		// Get node before pos;
		while (beforeNew->getLink() != NULL && i < pos - 1)
		{
			beforeNew = beforeNew->getLink();
			++i;
		}
		Node * afterNew = beforeNew->getLink();

		beforeNew->setLink(newNode);
		newNode->setLink(afterNew);

		++count;

		return 0;
	}
		
}



void AnyList::deleteNode(int)
{

}



void AnyList::print() const
{
	if (first == NULL || count == 0)
	{
		std::cout << "List is empty! " << std::endl;
		std::cout << "Size: " << count << std::endl;
	}
		

	else
	{
		Node * temp = first;
		// Traverse
		std::cout << "List: " << temp->getData();


		temp = temp->getLink();

		while (temp != NULL)
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