class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        // suppose everyone can use boat
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

