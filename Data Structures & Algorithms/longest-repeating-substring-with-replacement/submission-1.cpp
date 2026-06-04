class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 1;
        vector<int> arr(26, 0);
        int maxFreq = 0;
        int mx = 0;
        while (r <= s.length()) {
            int curCnt = ++arr[s[r-1]- 'A'];
            maxFreq = max(maxFreq, curCnt);
            if (r-l-maxFreq > k) {// XXXYYZ
                arr[s[l]-'A']--;
                l++;
            }
            if (r-l > mx) mx = r - l;

            r++;
        }
        return mx;
    }
};
