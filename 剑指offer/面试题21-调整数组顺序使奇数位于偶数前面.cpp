// 

// 1. 前后指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < r && (nums[l] & 1) == 1) l++;
            while (l < r && (nums[r] & 1) == 0) r--;
            if (l < r) swap(nums[l], nums[r]);
        }
        return nums;
    }
};

// 1.5 优化：因为交换完后 nums[l] 肯定是奇数，nums[r] 肯定是偶数，所以 l++， r++
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < r && (nums[l] & 1) == 1) l++;
            while (l < r && (nums[r] & 1) == 0) r--;
            if (l < r) swap(nums[l++], nums[r--]);
        }
        return nums;
    }
};

// 2. 快慢指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int s = 0, f = 0;
        size_t size = nums.size();
        while (f < size) {
            if ((nums[f] & 1) == 1) {
                swap(nums[s], nums[f]);
                s++;
            }
            f++;
        }
        return nums;
    }
};