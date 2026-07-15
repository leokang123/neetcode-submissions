/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 0 ;
        long long high = n+1;

        while (low + 1 < high) {
            long long mid = (long long)(low + high) / 2;
            int res = guess((int)mid);
            if (res > 0) low = mid;
            else if (res < 0) high = mid;
            else return mid;
        }

        return high;
        
    }
};