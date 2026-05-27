class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // o(n)
        int m = *max_element(people.begin(), people.end());
        vector<int> cnt(m+1, 0);
        for (auto w : people) {
            cnt[w]++;
        }
        int idx = 0, i = 1;
        while (idx < people.size()) {
            while (cnt[i] == 0) {
                i++;
            }
            people[idx++] = i;
            cnt[i]--;
        }

        int l = 0;
        int r = people.size() - 1;
        int res = 0;
        while (l < r) {
            int sum = people[l] + people[r];
            if (sum <= limit) l++;
            r--;
            res++;
        }
        if (l == r) res++;
        return res;
    }
};

// 1 2 4 5 


// 1 2 2 3 3 

