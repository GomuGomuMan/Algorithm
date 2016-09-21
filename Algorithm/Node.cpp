#include "Node.h"

AnyList::AnyList()
{
	first = NULL;
	count = 0;
}



void AnyList::insertFront(const int newData)
{
	Node * newNode = new Node;

	newNode->setData(newData);
	newNode->setLink(first);

	if (!first|| count == 0)
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



void AnyList::insertBack(const int newData)
{
	if (!first || count == 0)
		insertFront(newData);

	else
	{
		Node * newNode = new Node;

		newNode->setData(newData);
		newNode->setLink(NULL);

		Node * temp = first;

		// Traverse
		while (temp->getLink())
			temp = temp->getLink();

		temp->setLink(newNode);

		++count;
	}

	
}



int AnyList::insertPos(const int pos, const int newData)
{
	if (!first || count == 0)
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
		while (beforeNew->getLink() && i < pos - 1)
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

/*
	pos1 cannot be at the end
	pos2 cannot be at the beginning
*/
void AnyList::swap(const int pos1, const int pos2)
{
	if (!first || count == 0)
		std::cerr << "List is empty. Please specify position at 0 to insert. " << std::endl;

	else if (pos1 < 0 || pos2 < 0)
		std::cerr << "Position specified is negative. Please specify position in range [0, " + std::to_string(count - 1) + "]." << std::endl;

	else if (pos1 == pos2)
		std::cerr << "Specified positions are the same. Please specify again. " << std::endl;

	else if (pos1 > count - 1 || pos2 > count - 1)
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
		Node * firstNode, * after1stNode;
		int currentPos = 0;
		
		if (pos1 == 0)
		{
			before1stNode = NULL;
			firstNode = first;
			after1stNode = firstNode->getLink();
		}
		else
		{
			while (before1stNode->getLink() && currentPos < pos1 - 1)
			{
				before1stNode = before1stNode->getLink();
				++currentPos;
			}
			firstNode = before1stNode->getLink();
			after1stNode = firstNode->getLink();
		}

		// Test Node 1
		/*std::cout << "pos1: " << pos1 << std::endl;
		if (before1stNode != NULL)
			std::cout << "before1stNode: " << before1stNode->getData() << std::endl;
		std::cout << "firstNode: " << firstNode->getData() << std::endl;
		if (after1stNode != NULL)
			std::cout << "after1stNode: " << after1stNode->getData() << std::endl;
		std::cout << std::endl;*/


		// Find Node 2
		Node * before2ndNode = firstNode;
		Node * secondNode, * after2ndNode;

		while (before2ndNode->getLink() && currentPos < pos2 - 1)
		{
			before2ndNode = before2ndNode->getLink();
			++currentPos;
		}
		secondNode = before2ndNode->getLink();
		after2ndNode = secondNode->getLink();

		// Test Node 2
		/*std::cout << "pos2: " << pos2 << std::endl;
		std::cout << "before2ndNode: " << before2ndNode->getData() << std::endl;
		std::cout << "secondNode: " << secondNode->getData() << std::endl;
		if (after2ndNode != NULL)
			std::cout << "after2ndNode: " << after2ndNode->getData() << std::endl;
		std::cout << std::endl;*/

		// Swap
		if (!before1stNode)
		{
			first = secondNode;
			secondNode->setLink(after1stNode);
			before2ndNode->setLink(firstNode);
			firstNode->setLink(after2ndNode);
		}

		// Handle case: Node - firstNode - secondNode - Node
		else if (after1stNode == secondNode)
		{
			before1stNode->setLink(secondNode);
			secondNode->setLink(firstNode);
			firstNode->setLink(after2ndNode);
		}

		else
		{
			before1stNode->setLink(secondNode);
			secondNode->setLink(after1stNode);
			before2ndNode->setLink(firstNode);
			firstNode->setLink(after2ndNode);
		}		
	}

}



void AnyList::deleteNode(const int pos)
{
	if (!first || count == 0)
		std::cerr << "List is empty. Delete operation is NOT possible. " << std::endl;

	else if (pos < 0)
		std::cerr << "Position specified is negative. Please specify position in range [0, " + std::to_string(count - 1) + "]." << std::endl;

	else if (pos > count - 1)
	{
		std::cerr << "Position specified exceeds the amount of node available." << std::endl;
		std::cerr << "Please specify position in range [0, " + std::to_string(count - 1) + "]." << std::endl;
	}

	else
	{
		Node * node;
		// Case: count = 1
		if (count == 1)
		{
			node = first;
			first = NULL;
		}
			

		else if (pos == 0)
		{
			node = first;
			first = node->getLink();
		}

		else
		{
			Node * beforeNode = first;
			Node * afterNode;
			int currentPos = 0;

			while (beforeNode->getLink() && currentPos < pos - 1)
			{
				beforeNode = beforeNode->getLink();
				++currentPos;
			}

			node = beforeNode->getLink();
			afterNode = node->getLink();
			beforeNode->setLink(afterNode);
		}

		delete node;

		--count;
	}
}



void AnyList::print() const
{
	// !first <=> first != NULL
	if (!first || count == 0)
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

		while (temp)
		{
			std::cout << ", " << temp->getData();
			temp = temp->getLink();
		}

		
		std::cout << std::endl;
		std::cout << "Size: " << count << std::endl;
	}
}



AnyList::~AnyList()
{
	std::cout << "Object is being deleted" << std::endl;
	Node * current = first;
	while (current)
	{
		Node * traverse = current->getLink();
		delete current;
		current = traverse;
	}
}