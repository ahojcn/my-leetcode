// https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&&tqId=33257&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    int cutRope(int number) {
        if (number == 2) return 1;
        if (number == 3) return 2;

        int x = number % 3;
        int y = number / 3;
        if (x == 0) return pow(3, y);
        if (x == 1) return pow(3, y - 1) * 2 * 2;
        if (x == 2) return pow(3, y) * 2;
    }
};

