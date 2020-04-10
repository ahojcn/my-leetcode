// https://leetcode-cn.com/problems/check-permutation-lcci/

// 1. 排序 比较
// 0 ms	6.2 MB
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

// 2. 位运算
// 0 ms	6.3 MB
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int bin_s1 = 0, bin_s2 = 0;
        for (char c : s1) {
            bin_s1 = bin_s1 | (1 << (c - 'a'));
        }
        for (char c : s2) {
            bin_s2 = bin_s2 | (1 << (c - 'a'));
        }
        return bin_s1 == bin_s2;
    }
};