class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int r = 0;
        int res = 0;
        for (auto c : s) {
            // if find dup char, erase substring in charSet, reset
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(c);
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
