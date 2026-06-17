class Solution {
public:
    int abs(int a) {
        if (a < 0) return -1 * a;
        return a;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = 0;
        // if (k == arr.size()) return arr;
        for (r = 0; r < arr.size() ; r++) {
            if (r - l < k) continue;
            // a is not closer than b
            if (!((abs(arr[l] - x) < abs(arr[r] - x)) || (abs(arr[l] - x) == abs(arr[r] - x) && arr[l] < arr[r]))) {
                l++;
            } else {
                // a is closer than b, ending 
                break;
            }

        }
        vector<int> ans(arr.begin() + l, arr.begin() + r);
        return ans;
    }
};
