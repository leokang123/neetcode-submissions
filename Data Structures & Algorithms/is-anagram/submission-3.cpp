class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> check(27);
        if (s.length() != t.length()) return false;
        for (int i = 0 ; i < s.length() ; i++) {
            check[s[i] - 'a']++;
            check[t[i] - 'a']--;
        }
        for (auto c : check) {
            if (c != 0) return false;
        }
        return true;
    }
};
