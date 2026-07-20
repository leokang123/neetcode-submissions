class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx = 0;
        int maxVal = 0;
        unordered_set<char> st;
        for (int i = 0 ; i < s.length(); i++) {
            char c = s[i];
            while (st.find(c) != st.end()) {
                st.erase(s[idx]);
                idx++;
            }
            maxVal = max(maxVal, i - idx + 1);
            st.insert(s[i]);

        }

        return maxVal;
        
    }
};
