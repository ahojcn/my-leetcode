// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

// 1. 暴力
// 时间 O(n) 空间 O(n)
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (auto& c : s) {
            if (c != ' ') {
                ans += c;
            } else {
                ans += "%20";
            }
        }
        return ans;
    }
};

// 2. 数空格，resize s，然后从后向前遍历移动

