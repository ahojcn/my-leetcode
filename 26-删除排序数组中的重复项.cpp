// 1. 暴力法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                }
                if (nums[i] == nums[j]) {
                    nums.erase(nums.begin() + j);
                    j--;
                }
            }
        }
        return nums.size();
    }
};

// 2. 双指针遍历法  16ms, 7.5mb
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        size_t slow = 0, fast = 1;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return ++slow;
    }
};
