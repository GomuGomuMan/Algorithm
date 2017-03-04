#include "Bit_Manipulation.h"

Bit_Manipulation::Bit_Manipulation()
{
	bit_size = 8;
}

std::string Bit_Manipulation::print_binary(int num) const
{
	/*
	 * Print bit from right to left
	 */
	/*for (int i = bit_size - 1; i >= 0; --i)
	{
		std::cout << ((num >> i) & 1);
	}
	std::cout << std::endl;*/


	/*
	 * Print bit from left to right and reverse
	 */
	std::ostringstream str;
	while (num)
	{
		str << (num & 1);
		num >>= 1;
	}
	std::string result = str.str();
	std::reverse(result.begin(), result.end());
	return result;

	/*
	 * Recursive printing left to right and reverse
	 */
}

int Bit_Manipulation::get_num_highbit(int num) const
{
	/*
	 * Running time: O(n) where n is the number of bit of the number.
	*/
	int sum_high = 0;
	for (int i = bit_size - 1; i >= 0; --i)
	{
		if (((num >> i) & 1) == 1)
			++sum_high;
	}
	return sum_high;
}