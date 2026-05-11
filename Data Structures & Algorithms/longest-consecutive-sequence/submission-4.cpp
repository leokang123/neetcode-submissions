class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        if (s.empty()) return 0;
        for (auto num : s) {
            int streak = 0, cur = num;
            while (s.find(cur) != s.end()) {
                streak++;
                cur++;
            }
            res = max(res, streak);
        }
        return res;
    }
};
