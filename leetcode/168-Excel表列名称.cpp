// https://leetcode-cn.com/problems/excel-sheet-column-title/

// K 进制
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        
        while (1 <= n)
        {
            n -= 1; // 每次减1
            res.push_back('A' + (n % 26));
            n /= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
