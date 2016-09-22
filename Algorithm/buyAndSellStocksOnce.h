#pragma once
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>


class BuyAndSellStocksOnce 
{
	public:
		BuyAndSellStocksOnce();
		void execute();
		void bruteforce_method(const std::vector<int>& prices);
		void printDescription() const;
		void askforInput();
		void initializeVector();
		int getMaxProfit() const;
		void printVector() const;

	private:
		int day_range;
		int max_profit;
		std::vector<int> prices;
};