class Solution {
public:
    bool isPalindrome(string s, int bp, int ep) {
        while(bp < ep) {
            if (s[bp++] != s[ep--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int bp = 0;
        int ep = s.length() - 1;
        while (bp < ep) {
            if (s[bp] != s[ep]) {
                    return isPalindrome(s, bp+1, ep) || isPalindrome(s, bp, ep-1);
            } 
            bp++;
            ep--;
        }
        return true;
    }
};