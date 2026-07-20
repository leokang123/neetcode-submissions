class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        int idx = 0;
        int maxVal = 0;
        set<char> st;
        for (int i = 0 ; i < s.length(); i++) {
            char c = s[i];
            if (st.find(c) != st.end()) {
                maxVal = max(maxVal, cnt);
                while (s[idx] != s[i]) {
                    st.erase(s[idx]);
                    idx++;
                    cnt--;
                }
                idx++;
                continue;
            } else {
                cnt++;
                maxVal = max(maxVal, cnt);
                st.insert(s[i]);
            }


        }
        return maxVal;
        
    }
};
