class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 이미 정렬되어있는 벡터 두개에서는 삽입 정렬처럼 정렬을 했을때 기존에 이미 정렬되어있던 부분은 안건드려도 됨 
        // 잘 와닿진 않은데 M+N 크기의 벡터에 이미 정렬된 벡터들이 들어갈 자리들은 정해져있음 
        // 정렬이 된 벡터끼리 합치면 합치고 남은 부분들은 알아서 정렬이 되어 있음 
        int last = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums1[m-1] > nums2[n-1]) {
                nums1[last] = nums1[m-1];
                m--;
            } else {
                nums1[last] = nums2[n-1];
                n--;
            }
            last--;
        }

        while (n > 0) {
            nums1[last] = nums2[n-1];
            n--;
            last--;
        }
    }
};

