// https://leetcode-cn.com/problems/palindrome-permutation-lcci/

// 1. 使用 set
class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> tmp;
        for (auto c : s) {
            auto it = tmp.find(c);
            if (it != tmp.end()) {
                tmp.erase(it);
            } else {
                tmp.insert(c);
            }
        }
        return tmp.size() <= 1;
    }
};

// 2. 使用 bitset
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> set;
        for (auto c : s) {
            set.flip(c);
        }
        return set.none() || set.count() == 1;
    }
};