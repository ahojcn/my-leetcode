// https://leetcode-cn.com/problems/search-insert-position/

// 1. 暴力
// 注意两个条件 a.当数组中没有元素的时候 b.最后一个元素也不比 target 大
// O(n)	O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t i = 0;
        while (i < nums.size()) {
            if (nums[i] >= target) {
                return i;
            }
            i++;
        }
        return i == nums.size() ? i : -1;
    }
};

// 2. 二分查找
// 注意循环终止条件、mid 的取值、以及 l+r 可能会越界！
// O(logn)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t l = 0, r = nums.size();
        while (l < r) {
            // size_t mid = (l + r) / 2;
            size_t mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            }
            if (nums[mid] > target) {
                r = mid;
            }
        }
        return l;
    }
};