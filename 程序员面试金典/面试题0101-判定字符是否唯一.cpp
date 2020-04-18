// https://leetcode-cn.com/problems/is-unique-lcci/submissions/

// 1. 暴力法 O(n^2)
// 0 ms	6.1 MB
class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() <= 1) {
            return true;
        }
        for (size_t i = 0; i < astr.size(); ++i) {
            for (size_t j = i + 1; j < astr.size(); ++j) {
                if (astr[i] == astr[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

// 2. 位操作法
// a-z 是 26 个字母，使用一个 int 的比特位来记录每个字母是否出现
class Solution {
public:
    bool isUnique(string astr) {
        int m = 0;
        for (size_t i = 0; i < astr.size(); ++i) {
            int t = astr[i] - 'a';
            if ((m & (1 << t)) != 0) {
                return false;
            } else {
                m = m | (1 << t);
            }
        }
        return true;
    }
};