#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>

class Bit_Manipulation
{
	public:
		// Constructor
		Bit_Manipulation();

		/* Print binary representation of a number */
		std::string print_binary(int num) const;

		/* Print number of 1 in a binary representation */
		int get_num_highbit(int num) const;

	private:
		int bit_size;
};