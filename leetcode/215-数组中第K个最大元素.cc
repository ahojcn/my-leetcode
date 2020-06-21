// 快排，分治

class Solution {
    int _partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];

        int j = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[++j]);
            }
        }
        swap(nums[left], nums[j]);
        return j;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int targetIndex = nums.size() - k;

        while (true) {
            int index = _partition(nums, left, right);
            if (index == targetIndex) return nums[index];
            else if (index < targetIndex) left = index + 1;
            else right = index - 1;
        }
    }
};

