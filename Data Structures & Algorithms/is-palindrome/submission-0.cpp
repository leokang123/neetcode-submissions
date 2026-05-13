class Solution {
public:
    bool isPalindrome(string s) {

        string str = "";
        for (auto c : s) {
            if (c>= 'a' && c <= 'z') str += c;
            else if (c >='A' && c <= 'Z') str += c + 32;
            else if (c >='0' && c <= '9') str += c;
        }
        int bp = 0;
        int ep = str.length() - 1;
        bool isPalindrome = true;
        while (bp <= ep) {
            if (str[bp] == ' ') {
                bp++;
                continue;
            }
            if (str[ep] == ' ') {
                ep--;
                continue;
            }
            if (str[bp++] != str[ep--]) {
                isPalindrome = false;
                break;
            }
        }

        return isPalindrome;
    }
};
