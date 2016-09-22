#include <regex>
#include "Node.h"
#include "buyAndSellStocksOnce.h"

void singlyLinkedList();

int main()
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "-------------------Algorithm Collection--------------------" << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	while (1)
	{
		std::cout << "Which algorithm/data structure/problem do you want to choose? " << std::endl;
		std::string selection;
		std::getline(std::cin, selection);
		
		if (std::regex_match(selection, std::regex("(\\s*)buyAndSellStocksOnce(\\s*)")))
		{
			/*buyAndSellStocksOnce();*/
			BuyAndSellStocksOnce problem;
			problem.execute();
		}
		else if (std::regex_match(selection, std::regex("(\\s*)singly linked list(\\s*)")))
		{
			singlyLinkedList();
		}
		else if (std::regex_match(selection, std::regex("(\\s*)quit(\\s*)")))
		{
			return 0;
		}

		std::cout << std::endl;
	}
}



void singlyLinkedList()
{
	int NUMBER_RANGE = 100;

	AnyList * list = new AnyList();

	// Test insertFront
	list->insertFront(rand() % NUMBER_RANGE);
	list->insertFront(rand() % NUMBER_RANGE);
	list->insertFront(rand() % NUMBER_RANGE);

	/* Test insertBack*/
	list->insertBack(rand() % NUMBER_RANGE);
	list->insertBack(rand() % NUMBER_RANGE);
	list->insertBack(rand() % NUMBER_RANGE);

	// Print original list
	std::cout << "Original ";
	list->print();
	std::cout << std::endl;

	// Test insertPos
	/*bool successful = true;

	if (list->insertPos(7, 20))
	std::cout << "Not successful!" << std::endl;*/


	// Test swap
	list->swap(0, 5);

	// Test delete
	/*list->deleteNode(0);*/


	// Print
	list->print();
	std::cout << std::endl;


	// Retrieve memory
	delete list;
	list = NULL;
}