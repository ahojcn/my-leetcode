// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/

// 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n & 1 == 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};


// 一个数 n 与一个比它小 1 的数（n - 1）进行 & 运算之后，得到的结果会消除 n 中最低位的 1.
// 示例1: 7 & 6
// 00111
//       &   =》 00110
// 00110

// 示例2: 8 & 7
// 01000
//       &   =》 00000
// 00111
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n != 0) {
            n &= n-1;
            ret ++;
        }
        return ret;
    }
};
