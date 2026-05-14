class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st(1001, 0);
        int p = 0;
        for (auto c : operations) {
            if (p != 0 && c == "C") p--;
            else if (p != 0 && c == "D") st[p++] = st[p-1] * 2;
            else if (p >= 2 && c == "+") {
                int a = st[p-2];
                int b = st[p-1];
                st[p++] = a + b;
            } else {
                st[p++] = stoi(c);
            }
        }

        int sum = 0;
        for (int i = 0 ; i < p ; i++) {
            sum += st[i];
        }
        return sum;
    }
};