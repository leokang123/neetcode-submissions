class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r = 0, l = 0;
        int res = 0;
        while (r < prices.size()) {
            if (l == r) {
                r++;
                continue;
            }
            if (prices[r] >= prices[r-1]) r++;
            else {
                res = max(res, prices[r-1] - prices[l]);
                if (prices[r] < prices[l]) l = r;
                else r++;
            }
        }
        res = max(res, prices[r-1] - prices[l]);
        return res;
    }
};
