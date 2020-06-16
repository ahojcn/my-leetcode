// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

// 1. 删除多余的重复项 时间 O(N^2) 空间 O(1)
// 耗费时间的点：移除元素
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, cnt = 1, len = nums.size();
        while (i < len) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
                if (cnt > 2) {
                    nums.erase(nums.begin() + i);
                    i--;
                    len--;
                }
            } else {
                cnt = 1;
            }
            i++;
        }
        return len;
    }
};

// 2. 时间 O(n) 空间 O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        
        int i = 1, j = 1, cnt = 1;
        while (i < nums.size()) {
            cout << i << ", " << j << endl;
            if (nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                cnt=1;
            }
            if (cnt <= 2) {
                nums[j++] = nums[i];
            }
            i++;
        }
        return j;
    }
};