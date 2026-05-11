class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (auto i : nums) s.insert(i);
        if (s.empty()) return 0;
        int cnt = 1;
        int maxCnt = 1;
        int prev = *s.begin();
        for (auto it = next(s.begin()) ; it != s.end() ; it++) {
            int cur = *it;
            if (cur == prev + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxCnt = max(maxCnt, cnt);
            prev = cur;
        }
        return maxCnt;
    }
};
