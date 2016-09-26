#pragma once
#include <iostream>
#include <vector>

class Fibonacci
{
	public:
		Fibonacci();
		void execute();
		void printDescription() const;
		void askforInput();
		int getValue() const;

		// Matrix Method
		void matrix_method();
		void matrix_multiply(std::vector<std::vector<int>>& result, const std::vector<std::vector<int>> initial) const;

	private:
		int position;
		int value;
};