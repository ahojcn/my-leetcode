// 计数排序思路
// 时间：O(n)  空间：O(k) k=颜色个数
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colorCount[3] = { 0 };
        for (int i = 0; i < nums.size(); ++i) {
            assert(nums[i] >= 0 && nums[i] <= 2);
            colorCount[nums[i]]++;
        }
        int d = 0;
        for (int i = 0; i < sizeof(colorCount)/sizeof(colorCount[0]); ++i) {
            for (int j = 0; j < colorCount[i]; ++j) {
                nums[d++] = i;
            }
        }
    }
};

// 三路快排思路
// 时间O(n) 空间O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // nums[0...zero] == 0
        // nums[zero+1...i-1] == 1
        // nums[two...n-1] == 2
        int zero = -1, two = nums.size();
        for (int i = 0; i < two; ) {
            if (nums[i] == 0) {
                swap(nums[++zero], nums[i++]);
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[--two]);
            }
        }
    }
};

