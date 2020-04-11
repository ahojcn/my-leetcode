// https://leetcode-cn.com/problems/sqrtx/solution/

// 1. 暴力遍历
// 32 ms	5.9 MB
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) {return 1;}
        int res = 0;
        for (long int i = 0; i < x; ++i) {
            if (i * i == x) {
                res = i;
                break;
            }
            if (i * i < x && (i+1)*(i+1) > x) {
                res = i;
                break;
            }
        }
        return res;
    }
};

// 2. 二分法
// 4 ms	6 MB
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 1, r = x / 2;

        while (l < r) {
        	// 这里一定取右中位数，如果取左中位数，代码会进入死循环
            long mid = (l + r + 1) / 2;
            long s = mid * mid;
            if (s > x) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};

// 3. 牛顿迭代法
// 8 ms	6 MB
class Solution {
public:
    int mySqrt(int x) {
        long int x0 = x;
        while (x0 * x0 > x) {
            x0 = (x0 + x/x0) / 2;
        }
        return x0;
    }
};