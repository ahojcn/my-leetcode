// https://leetcode-cn.com/problems/move-zeroes/

// 1. 空间 O(n) 时间 O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> non_zero_elements;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != 0) non_zero_elements.push_back(nums[i]);
        
        for (int i = 0; i < non_zero_elements.size(); ++i)
            nums[i] = non_zero_elements[i];
        
        for (int i = non_zero_elements.size(); i < nums.size(); ++i)
            nums[i] = 0;
    }
};

// 2. 时间 O(1) 空间 O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;  // nums[0, k) 的元素均为非 0 元素
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }

        for (int i = k; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};


// 3. 直接将 0 和 !0 元素交换位置
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0)
                swap(nums[i], nums[k++]);
        }
    }
};

// 4. 优化（i 和 k 指向同一个元素的时候，即数组中全为 0 的时候）
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != k) {
                    swap(nums[i], nums[k++]);
                } else {
                    k++;
                }
            }
        }
    }
};