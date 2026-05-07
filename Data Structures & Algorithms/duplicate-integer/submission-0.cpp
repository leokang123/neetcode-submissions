class Solution {
private:
    unordered_set<int> us;
public:
    bool hasDuplicate(vector<int>& nums) {
        for (auto i : nums) {
            if (us.count(i)) return true;
            us.insert(i);
        }
        return false;
    }
};