// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

// 1. pow
// 缺点：当n非常大的时候，保存起来非常大
class Solution {
public:
    vector<int> printNumbers(int n) {
        int size = pow(10, n);
        vector<int> ans(size - 1);
        for (int i = 0; i < size - 1; ++i) {
            ans[i] = i + 1;
        }
        return ans;
    }
};

