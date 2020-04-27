// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/

// 1. 直接遍历 O(n) O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) cnt++;
        }
        return cnt;
    }
};

// 2.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }

        int tmp_r = l;
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        int tmp_l = r;
        return tmp_r - tmp_l - 1;
    }
};