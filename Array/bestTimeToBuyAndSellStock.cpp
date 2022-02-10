/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Example 1:
      Input: prices = [7,1,5,3,6,4]
      Output: 5
      Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
      Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1)
        return 0;

    int maxProfit = 0;
    int minVal = 10000;

    if(prices[1] > prices[0]) {
        maxProfit = prices[1] - prices[0];
        minVal = prices[0];
    }
    else {
        minVal = prices[1];
    }

    for(int i = 2; i < prices.size(); i++) {
        if(prices[i] > minVal) {
            if(maxProfit < prices[i] - minVal)
                maxProfit = prices[i] - minVal;
        } else {
            minVal = prices[i];
        }
    }

    return maxProfit;
}

// Time Complexity = O(n)
