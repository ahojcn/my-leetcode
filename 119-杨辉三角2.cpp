// https://leetcode-cn.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            res[i] = 1;
            for (int j = i; j > 1; --j) {
                res[j - 1] = res[j - 1] + res[j - 2];
            }
        }
        return res;   
    }
};