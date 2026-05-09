class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";
        for (auto str : strs) {
            res += to_string(str.length()) + ',';
        }
        res += '#';
        for (auto str : strs) {
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        int pos = s.find('#');
        vector<int> sizes;
        int i = 0;
        while (i != pos) {
            int p = s.find(',', i);
            int a = stoi(s.substr(i, p-i));
            sizes.push_back(a);
            i = p+1;
        }
        i += 1;
        vector<string> res;
        for (auto sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;
    }
};
