#include "buyAndSellStocksOnce.h"



BuyAndSellStocksOnce::BuyAndSellStocksOnce()
{
	day_range = 0;
	max_profit = 0;
}

void BuyAndSellStocksOnce::execute()
{
	printDescription();
	askforInput();
	initializeVector();
	printVector();

	// Run brutefoce_method
	bruteforce_method(prices);

	std::cout << "Maximum profit can be made: " << getMaxProfit() << std::endl;
}

int BuyAndSellStocksOnce::getMaxProfit() const
{
	return max_profit;
}

void BuyAndSellStocksOnce::initializeVector()
{
	for (int i = 0; i < day_range; i++)
	{
		// Generate random value in day_range
		prices.push_back(rand() % day_range);
		/*std::cout << "Iteration " + std::to_string(i) + ": " + std::to_string(prices[i]) << std::endl;*/
	}
}


void BuyAndSellStocksOnce::askforInput()
{
	std::cout << "Please input a day range: ";
	std::cin >> day_range;
}


void BuyAndSellStocksOnce::bruteforce_method(const std::vector<int>& prices)
{
	auto start = std::chrono::high_resolution_clock::now();

	// Set inital min_price very high
	// If set 0 -> numerical error
	int min_price = std::numeric_limits<int>::max();

	// Traverse through array
	for (const int& price : prices)
	{
		int max_profit_today = price - min_price;
		max_profit = std::max(max_profit_today, max_profit);
		min_price = std::min(price, min_price);
	}

	std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " ms" << std::endl;
}



void BuyAndSellStocksOnce::printDescription() const
{
	std::cout << "Problem: Input - Array of stock price for a specified day range" << std::endl;
	std::cout << "         Output - Maximum profits by buying first then selling" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void BuyAndSellStocksOnce::printVector() const
{
	std::cout << "Generated array: " << prices[0];
	for (int i = 1; i < prices.size(); ++i)
		std::cout << ", " << prices[i];
	std::cout << std::endl;
}