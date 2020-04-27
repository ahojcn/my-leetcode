// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/


// 注意，有序。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == m) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};