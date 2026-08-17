class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int lowest, max_profit;
		lowest = prices[0], max_profit = 0;
		for(int price: prices){
			// imagine selling it today
			int profit = price - lowest;
			max_profit = max(profit, max_profit);
			lowest = lowest > price ? price : lowest;
		}
		return max_profit;
    }
};
