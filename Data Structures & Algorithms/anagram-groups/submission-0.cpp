class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> tmp;
        vector<int> check(strs.size());
        vector<vector<int>> cache(strs.size(), vector<int>(27, 0));
        for (int i = 0 ; i < strs.size() ; i++) {
            string str = strs[i];
            for (auto c : str) {
                cache[i][c-'a']++;
            }
        }
        // just try
        for (int i = 0 ; i < strs.size() ; i++) {
            if (check[i]) continue;
            check[i] = 1;
            tmp.push_back({strs[i]});
            int slength = strs[i].length();
            for (int j = 0 ; j < strs.size() ; j++) {
                if (i == j) continue;
                string ctr = strs[j];
                if (ctr.length() != slength) continue;
                int cnt = 0;
                vector<int> copyCache = cache[i];
                for (auto c : ctr) {
                    if (copyCache[c-'a'] <= 0) break;
                    copyCache[c-'a']--;
                    cnt++;
                }
                if (cnt == slength) {
                    tmp[tmp.size()-1].push_back(ctr);
                    check[j] = 1;
                }
            }
        }
        return tmp;
    }
};
