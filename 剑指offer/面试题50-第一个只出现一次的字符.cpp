// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/

// 1. unordered_map 保存了元素的顺序
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> ump;
        for (char c : s) {
            ump[c] ++;
        }
        for (char c : s) {
            if (ump[c] == 1) return c;
        }
        
        return ' ';
    }
};
