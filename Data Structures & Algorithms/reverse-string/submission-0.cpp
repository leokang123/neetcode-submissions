class Solution {
public:
    void reverseString(vector<char>& s) {
        int bp = 0;
        int ep = s.size() - 1;
        for (int i = 0 ; i < s.size() / 2 ; i++) swap(s[bp++], s[ep--]);
        
    }
};