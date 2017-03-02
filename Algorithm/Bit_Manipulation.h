#pragma once

#include <iostream>
#include <bitset>

class Bit_Manipulation
{
	public:
		// Constructor
		Bit_Manipulation();

		/* Print binary representation of a number */
		void print_binary(int num) const;

	private:
		int bit_size;
};