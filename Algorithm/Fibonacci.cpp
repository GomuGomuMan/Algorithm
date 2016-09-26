#include "Fibonacci.h"

Fibonacci::Fibonacci()
{
	position = 0;
	value = 0;
}



void Fibonacci::execute()
{
	printDescription();
	askforInput();
	matrix_method();
	std::cout << "Result: " << getValue() << std::endl;
}


void Fibonacci::printDescription() const
{
	std::cout << "Problem: Input - Position of the Fibonacci number series value" << std::endl;
	std::cout << "         Output - Value in the position" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}


void Fibonacci::askforInput()
{
	std::cout << "Please input a position: ";
	std::cin >> position;
}

int Fibonacci::getValue() const
{
	return value;
}



void Fibonacci::matrix_method()
{
	std::vector<std::vector<int>> matrix{ {1, 1}, {1, 0} };

	if (position == 0)
		value = matrix[1][1];
	else if (position == 1 || position == 2)
		value = matrix[0][1];
	else
	{
		int matrix_exponential = position - 1;
		std::vector<std::vector<int>> result = matrix;

		// Exponentiation by squaring
		if (matrix_exponential % 2 == 1)
		{
			matrix_multiply(result, matrix); // Get to n^2
			std::vector<std::vector<int>> squared_matrix = result;

			int expobysqr_exponential = (matrix_exponential - 1) / 2;
			while (expobysqr_exponential > 1)
			{
				matrix_multiply(result, squared_matrix);
				--expobysqr_exponential;
			}

			matrix_multiply(result, matrix);
		}

		else
		{
			matrix_multiply(result, matrix); // Get to n^2
			std::vector<std::vector<int>> squared_matrix = result;

			int expobysqr_exponential = matrix_exponential / 2;
			while (expobysqr_exponential > 1)
			{
				matrix_multiply(result, squared_matrix);
				--expobysqr_exponential;
			}
		}

		/*while (matrix_exponential > 1)
		{
			matrix_multiply(result, matrix);
			--matrix_exponential;
		}*/

		// Testing
		std::cout << "Result vector: " << std::endl;
		std::cout << "[" << result[0][0] << " " << result[0][1] << "]" << std::endl;
		std::cout << "[" << result[1][0] << " " << result[1][1] << "]" << std::endl;

		value = result[0][0];
	}
}



void Fibonacci::matrix_multiply(std::vector<std::vector<int>>& result, const std::vector<std::vector<int>> initial) const
{
	std::vector<std::vector<int>> temp_result = result;
	result[0][0] = temp_result[0][0] * initial[0][0] + temp_result[0][1] * initial[1][0];
	result[0][1] = temp_result[0][0] * initial[0][1] + temp_result[0][1] * initial[1][1];
	result[1][0] = temp_result[1][0] * initial[0][0] + temp_result[1][1] * initial[1][0];
	result[1][1] = temp_result[1][0] * initial[0][1] + temp_result[1][1] * initial[1][1];
}