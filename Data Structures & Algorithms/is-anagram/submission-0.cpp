class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> check(27);
        for (auto c : s) {
            check[c-'a']++;
        }
        for (auto c : t) {
            check[c-'a']--;
        }
        for (auto c : check) {
            if (c != 0) return false;
        }
        return true;
    }
};
