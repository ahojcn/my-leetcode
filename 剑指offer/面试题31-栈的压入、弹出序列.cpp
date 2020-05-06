// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // if (pushed.size() != popped.size()) return false;

        stack<int> s;
        int i = 0;
        for (auto item : pushed) {
            s.push(item);
            while (!s.empty() && s.top() == popped[i]) {
                s.pop();
                i++;
            }
        }
        return s.empty();
    }
};
