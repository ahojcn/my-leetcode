// https://leetcode-cn.com/problems/string-to-url-lcci/

// 1. 开辟额外空间
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res = "";
        for (int i = 0; i < length; ++i) {
            if (S[i] == ' ') {
                res += "%20";
            } else {
                res += S[i];
            }
        }
        return res;
    }
};


// 2. 原地修改
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int space_count = 0;
        for (int i = 0; i < length; ++i) {
            if (S[i] == ' ') space_count++;
        }

        int new_length = space_count * 2 + length;
        S[new_length] = '\0';
        for (int i = length - 1; i >= 0; --i) {
            if (S[i] == ' ') {
                S[new_length - 1] = '0';
                S[new_length - 2] = '2';
                S[new_length - 3] = '%';
                new_length -= 3;
            } else {
                S[new_length - 1] = S[i];
                new_length--;
            }
        }
        return S;
    }
};