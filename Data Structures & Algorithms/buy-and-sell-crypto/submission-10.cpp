class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int res = 0;
        for (int price : prices) {
            res = max(res, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return res;
    }
};
