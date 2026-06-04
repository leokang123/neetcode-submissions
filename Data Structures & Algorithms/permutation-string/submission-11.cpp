class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (auto c : s1) mp1[c]++;
        int l = 0;
        int cnt = 0;
        for (int r = 0 ; r < s2.length() ; r++) {
            if (mp1[s2[r]] == 0) {
                cout << s2[r] << ' ' ;
                while (l != r) {
                    if (mp1[s2[l]]) mp2[s2[l]]--;
                    l++;
                }
                l++;
                cnt = 0;
                continue;
            } else {
                while (mp2[s2[r]] + 1 > mp1[s2[r]]) {
                    mp2[s2[l]]--;
                    l++;
                    cnt--;
                }
                mp2[s2[r]]++;
                cnt++;
                cout << s2[r] << ' ' << cnt << ' ' ;
            }

            if (cnt == s1.length()) return true;
        }

        return false;
    }
};
