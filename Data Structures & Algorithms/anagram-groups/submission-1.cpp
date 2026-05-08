class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }
        vector<vector<string>> result(mp.size());
        int idx = 0;
        for (auto [t, s] : mp) {
            result[idx] = s;
            idx++;
        }
        return result;
    }

};
