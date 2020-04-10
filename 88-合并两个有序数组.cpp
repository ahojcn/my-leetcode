// https://leetcode-cn.com/problems/merge-sorted-array/

// 1. 合并、排序
// 时间复杂度O((m + n)*log(m + n))，空间复杂度O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        size_t i = m, j = 0;
        while (j < n) {
            nums1[i] = nums2[j];
            ++i; ++j;
        }
        sort(nums1.begin(), nums1.end());
    }
};

// 2. 从前向后
// 时间复杂度 O(m+n) 空间复杂度 O(m)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> cp(nums1.begin(), nums1.end());
        size_t i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (nums2[i] < cp[j]) {
                nums1[k] = nums2[i++];
            } else {
                nums1[k] = cp[j++];
            }
            k++;
        }
        while (i != n) {
            nums1[k++] = nums2[i++];
        }
        while (j != m) {
            nums1[k++] = cp[j++];
        }
    }
};

// 3. 从后向前
// 时间复杂度 O(m+n) 空间复杂度 O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0 && i >= 0) {
            nums1[k--] = (nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]);
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};