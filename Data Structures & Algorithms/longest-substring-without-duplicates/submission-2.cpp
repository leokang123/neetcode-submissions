class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int res = 0;
        for (auto c : s) {
            if(mp.find(c) != mp.end()) {
                l = max(mp[c]+1, l);
            }
            mp[c] = r;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
