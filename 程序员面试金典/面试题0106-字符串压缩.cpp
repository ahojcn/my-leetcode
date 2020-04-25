// https://leetcode-cn.com/problems/compress-string-lcci/

// 1. 计数器 模拟
class Solution {
public:
    string compressString(string S) {
        
        string res = "";

        int i = 0;
        while (i < S.size()) {
            int count = 1;
            char cur = S[i];

            for (int j = i + 1; j < S.size(); ++j) {
                if (S[j] == cur) count++;
                else break;
            }
            res += cur;
            res += to_string(count);

            i += count;
        }

        return res.size() >= S.size() ? S : res;
    }
};
