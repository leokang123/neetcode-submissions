class Solution {
private:
bool matchPair(char c1, char c2) {
    if (c1 == '(') return c2 == ')';
    else if (c1 == '{') return c2 == '}';
    else if (c1 == '[') return c2 == ']';
    return false;
}
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (!st.empty() && matchPair(st.top(), c)) st.pop();
            else st.push(c);
        }
        return st.empty();
    }
};
