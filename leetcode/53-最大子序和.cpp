// 暴力法
// 200/202 超时
class Solution {
    int _add(vector<int>& nums, size_t start, size_t end) {
        int sum = 0;
        for (size_t i = start; i <= end; ++i) {
            sum += nums[i];
        }
        return sum;
    }
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        size_t n = 0;
        int max = nums[0];
        while (n < nums.size()) {
            for (size_t start = 0; start < nums.size() - n; ++start) {
                int r = _add(nums, start, start + n);
                // cout << "n:" << n << " | start-end:"<<start << "-" << start + n << " | r:" << r << endl;
                if (r > max) {
                    max = r;
                }
            }
            n++;
        }
        return max;
    }
};

// 动态规划 TODO

// 贪心法 TODO

// 分治法 TODO
