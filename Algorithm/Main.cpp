#include <regex>
#include "Reference_Main.h"

void singlyLinkedList();

int main()
{
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << "-------------------Algorithm Collection--------------------" << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	BST<int> bst = BST<int>();
	bst.insert(5);
	bst.insert(1);
	bst.insert(6);
	bst.print_inorder();
	bst.print_preorder();
	bst.print_postorder();

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
		else if (std::regex_match(selection, std::regex("(\\s*)fibonacci(\\s*)")))
		{
			Fibonacci problem;
			problem.execute();

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