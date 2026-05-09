class Solution {
public:

    string encode(vector<string>& strs) {
        string e = "";
        for (auto s : strs) e += s + "<><>";
        return e;
    }

    vector<string> decode(string s) {
        int start = 0;
        int pos;
        vector<string> result;
        while ((pos = s.find("<><>", start)) != -1) {
            result.push_back(s.substr(start, pos-start));
            start = pos+4;
        }
        // result.push_back(s.substr(start));
        return result;
    }
};
