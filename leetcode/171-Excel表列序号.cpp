// https://leetcode-cn.com/problems/excel-sheet-column-number/

// K 进制
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (auto c : s) {
            ans = ans * 26 + (c - 'A') + 1;
        }

        return ans;
    }
};