// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/

// 对撞指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        vector<int> res;
        while (l < r) {
            int t = nums[l] + nums[r];
            if (t == target) {
                res.push_back(nums[l]);
                res.push_back(nums[r]);
                break;
            }
            if (t > target) {
                r--;
            }
            if (t < target) {
                l++;
            }
        }

        return res;
    }
};