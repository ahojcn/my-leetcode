//https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

// 1. 暴力 超时
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int ans = nums[0];
        bool has = false;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;

                if (nums[i] == nums[j]) {
                    has = true;
                    ans = nums[i];
                    break;
                }
            }
            if (has) break;
        }
        
        return ans;
    }
};

// 2. 排序，相同的元素会出现在一起
// 时间 O(n) 空间 O(1)  注意排序也耗费了时间和空间
// 156 ms	23.1 MB
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;
        for (i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                break;
            }
        }
        return nums[i];
    }
};

// 3. 使用 set 保存已经遍历过的数
// 时间 O(n) 空间 O(n)
// 176 ms	28.5 MB
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) return nums[i];
            
            s.insert(nums[i]);
        }
        return -1;
    }
};

// 4. 
// 如果没有重复数字，那么正常排序后，数字i应该在下标为i的位置，
// 所以思路是重头扫描数组，
// 遇到下标为i的数字如果不是i的话，（假设为m),
// 那么我们就拿与下标m的数字交换。
// 在交换过程中，如果有重复的数字发生，那么终止返回
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp;
        for(int i=0; i < nums.size(); i++){
            while (nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
