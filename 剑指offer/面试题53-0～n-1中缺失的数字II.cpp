// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/


// 1. 注意，有序。 二分查找
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

// 2. 求和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            sum1 += i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            sum2 += nums[i];
        }

        cout << sum1 << ", " << sum2 << endl;
        return abs(sum1 - sum2);
    }
};

// 2.5 优化求和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        sum1 = (0 + nums.size()) * (nums.size() + 1) / 2;
        for (int i = 0; i < nums.size(); ++i) {
            sum2 += nums[i];
        }

        return abs(sum1 - sum2);
    }
};