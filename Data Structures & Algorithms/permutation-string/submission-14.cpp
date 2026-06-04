class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // 처음 n개짜리 window 만들기
        for (int i = 0; i < n; i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        if (need == window) return true;

        // window를 한 칸씩 오른쪽으로 이동
        for (int r = n; r < m; r++) {
            window[s2[r] - 'a']++;       // 오른쪽 문자 추가
            window[s2[r - n] - 'a']--;   // 왼쪽 문자 제거

            if (need == window) return true;
        }

        return false;
    }
};
