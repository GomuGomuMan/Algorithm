#include "Bit_Manipulation.h"

Bit_Manipulation::Bit_Manipulation()
{
	bit_size = 8;
}

void Bit_Manipulation::print_binary(int num) const
{
	for (int i = bit_size - 1; i >= 0; --i)
	{
		std::cout << ((num >> i) & 1);
	}
	std::cout << std::endl;
}