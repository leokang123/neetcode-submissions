class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (auto c : s1) need[c]++;
        int l = 0;
        int cnt = 0;
        for (int r = 0 ; r < s2.length(); r++) {
            int cur = s2[r];
            if (!need.count(cur)) {
                window.clear();
                l = r+1;
                cnt = 0;
                continue;
            }

            while (window[cur] + 1 > need[cur]) {
                window[s2[l]]--;
                l++;
                cnt--;
            }
            window[cur]++;
            cnt++;

            if (cnt == s1.length()) return true;
        }

        return false;
    }
};
