// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/

// BFS
class Solution {
    int __getDigitSum(int x) {
        int ret = 0;
        while (x != 0) {
            int d = x % 10;
            ret += d;
            x /= 10;
        }
        return ret;
    }
public:
    int movingCount(int m, int n, int k) {
        if (0 == k) return 1;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};

        q.push(make_pair(0, 0));
        visited[0][0] = true;
        int result = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 2; ++i) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n 
                    || visited[tx][ty] 
                    || __getDigitSum(tx) + __getDigitSum(ty) > k)
                    continue; 
                // else
                q.push(make_pair(tx, ty));
                visited[tx][ty] = true;
                ++result;
            }
        }

        return result;
    }
};


// DFS

