class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto& num : nums) {
            if (s.find(num-1) != s.end()) continue;
            int res = 0;
            while (s.find(num) != s.end()) {
                res++;
                num += 1;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};
