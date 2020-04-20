// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

// 1. 暴力
// 时间 O(m*n) 空间 O(1)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

// 1.5 每一行二分查找
// 二分的时间复杂度 O(logn)
// 时间复杂度 n * O(logn)，空间复杂度 O(1)
// 56 ms	13.1 MB
class Solution {
    bool binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            if (binarySearch(matrix[i], target)) return true;
        }
        return false;
    }
};

// 2. 利用题目中的条件（从左到右递增，从上到下递增）
// 时间 O(m+n) 空间 O(1)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j <= matrix[i].size()) {
            int flag = matrix[i][j];
            if (target == flag) {
                return true;
            }
            if (target < flag) {
                i--;
            }
            if (target > flag) {
                j++;
            }
        }
        return false;
    }
};
