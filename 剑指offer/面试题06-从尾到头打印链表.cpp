// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/

// 在编写代码前，要跟面试官沟通清楚，
// 根据面试官提出的不同性能需求
// （时间效率优先 or 空间效率优先 or 不允许改变链表结构 or 云云）
// 给出不同的算法。

// 1. 遍历一遍链表，翻转数组
// 8 ms	8.7 MB
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        ListNode* cur = head;
        while (cur) {
            ans.push_back(cur->val);
            cur = cur->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 2. 遍历两边链表
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        while (cur) {
            cur = cur->next;
            count++;
        }
        vector<int> nums(count);
        cur = head;
        for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
            *i = cur->val;
            cur = cur->next;
        }
        return nums;
    }
};

// 3. 递归
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (!head) return {};

        vector<int> nums = reversePrint(head->next);
        nums.push_back(head->val);
        return nums;
    }
};

// 4. 栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        ListNode* cur = head;
        while (cur) {
            s.push(cur->val);
            cur = cur->next;
        }
        vector<int> nums;
        while (!s.empty()) {
            nums.push_back(s.top());
            s.pop();
        }
        return nums;
    }
};

// 5. 改变链表结构
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head = pre;

        vector<int> nums;
        while (pre) {
            nums.push_back(pre->val);
            pre = pre->next;
        }
        return nums;
    }
};

