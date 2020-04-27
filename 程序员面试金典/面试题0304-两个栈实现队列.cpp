// https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci/

class MyQueue {
private:
    stack<int> sa;
    stack<int> sb;

    void __move_a2b() {
        while (!sa.empty()) {
            int t = sa.top();
            sa.pop();
            sb.push(t);
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sa.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (sb.empty()) {
            __move_a2b();
        }

        int ret = sb.top();
        sb.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (sb.empty()) {
            __move_a2b();
        }
        return sb.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sa.empty() && sb.empty();
    }
};