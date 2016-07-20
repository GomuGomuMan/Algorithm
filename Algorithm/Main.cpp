#include "Node.h"


int main()
{
	AnyList * list = new AnyList();

	// Test insertFront
	list->insertFront(1);
	list->insertFront(2);
	list->insertFront(3);
	
	// Test insertBack
	list->insertBack(4);
	list->insertBack(5);
	list->insertBack(6);

	// Test insertPos
	/*bool successful = true;

	if (list->insertPos(0, 20))
		std::cout << "Not successful!" << std::endl;*/


	// Test swap
	list->swap(1, 1);
	

	// Print
	list->print();


	// Retrieve memory
	delete list;
	list = NULL;

	system("Pause");
	return 0;
}