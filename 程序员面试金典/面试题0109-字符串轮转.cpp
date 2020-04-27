// https://leetcode-cn.com/problems/string-rotation-lcci/

// 1. 4 ms	8.1 MB	
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) { return false; }

        string s2s2 = s2 + s2;
        
        if (strstr(s2s2.c_str(), s1.c_str())) {
            return true;
        }

        return false;
    }
};

// 2. 16 ms	8.2 MB
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) { return false; }
        
        return (s2 + s2).find(s1) != -1;
    }
};

