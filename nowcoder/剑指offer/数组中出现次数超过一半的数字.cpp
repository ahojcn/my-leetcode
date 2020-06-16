// https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> nums) {
        int x = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) x = nums[i];
            int d = nums[i] == x ? 1 : -1;
            count += d;
        }
        
        // 判断一下 x 是不是众数
        count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += (x == nums[i] ? 1 : 0);
        }
        
        return count > nums.size() / 2 ? x : 0;
    }
};