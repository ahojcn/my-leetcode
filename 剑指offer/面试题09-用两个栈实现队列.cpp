// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

// 1. 思路：两个 stack，s1 和 s2
// 每次 appendTail，将数据 push 进 s1
// 每次 deleteHead，如果 s2 不为空，将 s2.top 返回，为空就将 s1 中元素逐一 pop 到 s2 中
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {}
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            if(s1.empty()){
                return -1;
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }               
            }
        }
        int head=s2.top();
        s2.pop();
        return head;
    }
};