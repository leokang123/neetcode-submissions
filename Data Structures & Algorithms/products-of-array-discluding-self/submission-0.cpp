class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt = 0;
        int res = 1;
        for (auto n : nums) {
            if (n != 0) res *= n;
            else {
                zeroCnt++;
            }
        }
        vector<int> result;
        for (auto n : nums) {
            if (n == 0) {
                if (zeroCnt == 1) result.push_back(res);
                else result.push_back(0);
            } else {
                if (zeroCnt) result.push_back(0);
                else result.push_back(res/n);
            }
        }
        return result;
    }
};