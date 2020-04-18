// 1. 暴力法
// 要注意迭代器失效的问题
// 4 ms	6.3 MB
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it == val) {
                it = nums.erase(it);
            } else {
                ++it;
            }
        }
        return nums.size();
    }
};

// 2. 双指针法，类似于26删除数组中的重复项
// 0 ms	6.3 MB
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t s = 0, f = 0;
        while (f < nums.size()) {
            if (nums[f] != val) {
                nums[s++] = nums[f];
            }
            f++;
        }
        return s;
    }
};

// 3. 双指针法，当 nums 中只有较少的元素 == val 的时候
// 方法2中，会将一些元素做不必要的移位操作
// 4 ms	6.4 MB
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t n = nums.size();
        size_t i = 0;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];  // 和最后一个有效值交换
                --n;  // 有效元素 - 1
            } else {
                ++i;
            }
        }
        return n;
    }
};