class Solution {
public:
    int mySqrt(int x) {
        int high = x/2 + 1;
        int low = 0;
        if (x == 1) return 1;
        while (low + 1 < high) {
            int mid = (high + low) / 2;
            long long res = (long)mid * mid;
            if (res > x) high = mid;
            else low = mid;
        }

        return low;
    }
};