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
	if (first == NULL || count == 0)
	{
		std::cerr << "List is empty. Please specify position at 0 to insert. " << std::endl;
		return 1;
	}

	else if (pos > count)
	{
		std::cerr << "Position specified exceeds the amount of node available." << std::endl;
		std::cerr << "Please try a position lower than " + std::to_string(count) << std::endl;
		return 1;
	}

	else if (pos == 0)
	{
		insertFront(newData);
		return 0;
	}

	else if (pos == count - 1)
	{
		insertBack(newData);
		return 0;
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
		// Get node after pos
		Node * afterNew = beforeNew->getLink();

		beforeNew->setLink(newNode);
		newNode->setLink(afterNew);

		++count;

		return 0;
	}
		
}

void AnyList::swap(int pos1, int pos2)
{
	if (first == NULL || count == 0)
		std::cerr << "List is empty. Please specify position at 0 to insert. " << std::endl;


	else if (pos1 == pos2)
		std::cerr << "Specified positions are the same. Please specify again. " << std::endl;

	else if (pos1 > count - 1|| pos2 > count - 1)
	{
		std::cerr << "Position specified exceeds the amount of node available." << std::endl;
		std::cerr << "Please try a position lower than " + std::to_string(count) << std::endl;
	}

	// Put pos1 & pos2 in order
	else if (pos1 > pos2)
	{
		swap(pos2, pos1);
	}

	else
	{
		// Find Node 1
		Node * before1stNode = first;
		Node *firstNode;
		Node *after1stNode = NULL;
		int i = 0;
		
		if (pos1 == 0)
		{
			before1stNode = NULL;
			firstNode = first;
			after1stNode = firstNode->getLink();
		}
		else
		{
			while (before1stNode->getLink() != NULL && i < pos1 - 1)
			{
				before1stNode = before1stNode->getLink();
				++i;
			}
			firstNode = before1stNode->getLink();
			after1stNode = firstNode->getLink();
		}

		// Test Node 1
		std::cout << "pos1: " << pos1 << std::endl;
		if (before1stNode != NULL)
			std::cout << "before1stNode: " << before1stNode->getData() << std::endl;
		std::cout << "firstNode: " << firstNode->getData() << std::endl;
		if (after1stNode != NULL)
			std::cout << "after1stNode: " << after1stNode->getData() << std::endl;
		std::cout << std::endl;


		//// Find Node 1
		//bool isBefore1stNull = false;
		//Node * before1stNode = first;
		//Node *firstNode, *after1stNode;
		//int i = 0;

		//if (pos1 == 0) // Handle case where pos1 is front
		//{
		//	before1stNode = NULL;
		//	firstNode = first;
		//	after1stNode = firstNode->getLink();
		//	isBefore1stNull = true;
		//}

		//else
		//{
		//	while (before1stNode->getLink() != NULL && i < pos1 - 1)
		//	{
		//		before1stNode = before1stNode->getLink();
		//		++i;
		//	}
		//	firstNode = before1stNode->getLink();
		//	after1stNode = firstNode->getLink();

		//	
		//}
		//
		//// Testing
		//std::cout << "pos1: " << pos1 << std::endl;
		//if (before1stNode != NULL)
		//	std::cout << "before1stNode: " << before1stNode->getData() << std::endl;
		//std::cout << "firstNode: " << firstNode->getData() << std::endl;
		//std::cout << "after1stNode: " << after1stNode->getData() << std::endl;
		//std::cout << std::endl;



		//// Find Node 2
		//Node * before2ndNode = first;
		//Node * secondNode, *after2ndNode;
		//int j = 0;
		//while (before2ndNode->getLink() != NULL && j < pos2 - 1)
		//{
		//	before2ndNode = before2ndNode->getLink();
		//	++j;
		//}
		//secondNode = before2ndNode->getLink();
		//after2ndNode = secondNode->getLink();



		//// Testing
		//std::cout << "pos2: " << pos2 << std::endl;
		//std::cout << "before2ndNode: " << before2ndNode->getData() << std::endl;
		//std::cout << "secondNode: " << secondNode->getData() << std::endl;
		//std::cout << "after2ndNode: " << after2ndNode->getData() << std::endl;
		//std::cout << std::endl;



		//// Swap
		//if (isBefore1stNull)
		//{
		//	secondNode->setLink(after1stNode);

		//	before2ndNode->setLink(firstNode);
		//	firstNode->setLink(after2ndNode);
		//	first = secondNode;
		//}
		//	
		//



		//// Swap
		///*before1stNode->setLink(secondNode);
		//secondNode->setLink(after1stNode);

		//before2ndNode->setLink(firstNode);
		//firstNode->setLink(after2ndNode);*/
		
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