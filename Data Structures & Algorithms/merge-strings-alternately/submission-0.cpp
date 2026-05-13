class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ap = 0;
        int bp = 0;
        string str = "";

        while (ap < word1.length() && bp < word2.length()) {
            str += word1[ap++];
            str += word2[bp++];
        }

        while(ap < word1.length()) str += word1[ap++];
        while(bp < word2.length()) str += word2[bp++];
        return str;
    }
};