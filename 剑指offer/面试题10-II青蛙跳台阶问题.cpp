// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

// 类斐波那契数列解法
class Solution {
public:
    int numWays(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1, sum;
        for(int i = 2; i < n + 1; i++){
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};