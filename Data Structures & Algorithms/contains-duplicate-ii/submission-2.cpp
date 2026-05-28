class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        deque<int> dq;

        for (auto num : nums) {
            for (auto i : dq) {
                if (i == num) return true;
            }
            if (dq.size() >= k) dq.pop_front();
            dq.push_back(num);
        }
        return false;
    }
};