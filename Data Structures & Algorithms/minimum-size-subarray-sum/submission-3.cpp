class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int res = 0;
        int minNum = nums.size() + 1;
        for (r = 0 ; r < nums.size() ; r++) {
            res += nums[r];
            while (r >= l && res >= target) {
                minNum = min(minNum, r - l + 1);
                res -= nums[l];
                l++;
            }
        }
        if (minNum == nums.size() + 1) return 0;
        return minNum;
    }
};