// https://leetcode-cn.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = false;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            if (i == 0) {
                digits[i] = 1;
                digits.push_back(0);
            } else {
                digits[i] = 0;
            }
        }
        return digits;
    }
};