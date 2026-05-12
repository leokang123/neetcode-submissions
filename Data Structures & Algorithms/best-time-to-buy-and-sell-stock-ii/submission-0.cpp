class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int base = prices[0];
        int profit = 0;
        for (int i = 1 ; i < prices.size() ; i++) {
            if (base < prices[i]) 
                profit += prices[i] - base;
            base = prices[i];
        }
        return profit;
    }
};