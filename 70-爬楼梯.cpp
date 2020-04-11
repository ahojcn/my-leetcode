// 

// 1. 直接递归
// 在 44 的时候超时！
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// 2. 记忆递归
// 空间复杂度 O(n)
// 时间复杂度较高，因为维护了一个 map，map 在索引的时候复杂度为 O(logn)，总时间复杂度 O(nlongn)
// 4 ms	6.4 MB
class Solution {
public:
    map<int, int> m;
    int climbStairs(int n) {
        if (n <= 2) return n;
        if (m.find(n) != m.end()) return m[n];

        m[n-1] = climbStairs(n - 1);
        m[n-2] = climbStairs(n - 2);
        return  m[n-1]+m[n-2];
    }
};

// 3. 记忆递归优化
// 空间复杂度 O(n)
// 时间复杂度 O(n)
// 4 ms	6.2 MB
class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n + 1);
        return _climbStairs(v, n);
    }

    int _climbStairs(vector<int>& v, int n) {
        if (n <= 2) return n;
        if (v[n] != 0) return v[n];
        v[n - 1] = _climbStairs(v, n - 1);
        v[n - 2] = _climbStairs(v, n - 2);
        return v[n - 1] + v[n - 2];
    }
};

// 4. dp 动态规划
// 空间复杂度 O(n)，时间复杂度 O(n)
// dp(i) = dp(i - 1) + dp(i - 2)
// 0 ms	6.2 MB
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[0] = 0; dp[1] = 1; dp[2] = 2;
        for (size_t i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 5. 斐波那契数列
// 时间复杂度 O(n) 空间复杂度 O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int first = 1, second = 2;
        for (int i = 3; i <= n; ++i) {
            int thired = first + second;
            first = second;
            second = thired;
        }
        return second;
    }
};
