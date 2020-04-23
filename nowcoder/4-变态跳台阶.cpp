// https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    int jumpFloorII(int n) {
        
        if (n <= 0) return -1;
        
        if (n < 2) return 1;
        return 2 * jumpFloorII(n - 1);
    }
};