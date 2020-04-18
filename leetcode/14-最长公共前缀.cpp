// 暴力1   4ms, 6.9mb
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string res = strs[0];
        for (int i = 0; i < strs.size(); ++i) {
            int j = 0;
            for (j = 0; j < res.size() && j < strs[i].size(); ++j) {
                if (res[j] != strs[i][j]) {
                    break;
                }
            }
            res = res.substr(0, j);
            if (res == "") {
                return "";
            }
        }

        return res;
    }
};

// 暴力2   4ms, 6.6mb
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        // 找出最短的字符串长度
        int min_len = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].size() <= min_len) {
                min_len = strs[i].size();
            }
        }

        // 找出公共字符并加到 res 上
        string res = "";
        for (int i = 0; i < min_len; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (c != strs[j][i]) {
                    return res;
                }
            }
            res += c;
        }

        return res;
    }
};