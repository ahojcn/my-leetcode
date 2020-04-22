// https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/

// 1. 排序
// 时间 O(nlogn) 空间 O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];;
    }
};

// 2. hash
// 时间 O(n) 空间 O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
            if (m[nums[i]] > nums.size() / 2) return nums[i];
        }
        return 0;
    }
};

// 3. 摩尔投票法  O(n)  O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) x = nums[i];
            int d = nums[i] == x ? 1 : -1;
            count += d;
        }
        return x;
    }
};
