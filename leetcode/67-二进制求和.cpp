// https://leetcode-cn.com/problems/add-binary/

// 1. 从后向前加
// 如果a，b长度不相等，在短的前面补 0
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1;
        while (i < j) {
            a = '0' + a;
            ++i;
        }
        while (j < i) {
            b = '0' + b;
            ++j;
        }

        i = a.size() - 1; j = b.size() - 1;
        bool flag = false;
        while (i >= 0 && j >= 0) {
            if (flag == false) {  // 如果有进位
                if (a[i] == '0' || b[j] == '0') {
                    char c = a[i] == '1' ? a[i] : b[j];
                    res = c + res;
                } else {
                    flag = true;
                    res = '0' + res;
                }
            } else {  // 如果上一个计算完没有进位
                if (a[i] == '1' && b[j] == '1') {
                    res = '1' + res;
                } else if (a[i] == '0' && b[j] == '0') {
                    flag = false;
                    res = '1' + res;
                } else {
                    res = '0' + res;
                }
            }
            --j; --i;
        }

        // 如果所有都计算完后还有进位
        if (flag == true) {
            res = '1' + res;
        }
        return res;
    }
};


// 2. 评论区解法
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int x = i < 0 ? 0 : a[i] - '0';
            int y = j < 0 ? 0 : b[j] - '0';
            int sum = (x + y + carry) % 2;
            carry = (x + y + carry) / 2;
            // res = char(sum + '0') + res;
            res.insert(0, 1, sum + '0');
            --i; --j;
        }
        return res;
    }
};
