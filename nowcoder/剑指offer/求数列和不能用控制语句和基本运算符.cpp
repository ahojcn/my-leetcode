// https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tags=&title=&diffculty=0&judgeStatus=0&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};