// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/

class MinStack {
private:
    stack<int> sa;
    stack<int> sb;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        sa.push(x);
        if (sb.empty() || x <= sb.top()) {
            sb.push(x);
        }
    }
    
    void pop() {
        if (sa.empty()) return;
        if (sb.top() == sa.top()) sb.pop();
        sa.pop();
    }
    
    int top() {
        return sa.top();
    }
    
    int min() {
        return sb.top();
    }
};