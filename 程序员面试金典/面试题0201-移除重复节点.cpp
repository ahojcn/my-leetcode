// https://leetcode-cn.com/problems/remove-duplicate-node-lcci/

// 1. 时间 O(n) 空间 O(n)
// 保存已经走过的 val，如果当前节点的 val 之前出现过，删除当前节点
// 92 ms	17.5 MB
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {

        set<int> s;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (s.find(cur->val) == s.end()) {
                // 如果这个节点的值之前没有
                s.insert(cur->val);
                pre = cur;
                cur = cur->next;
            } else {
                // 存在这个值，删除当前节点
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
        }
        return head;
    }
};

// 2. 时间O(n^2) 空间 O(1)
// 540 ms	15.4 MB
// 每次遇到一个节点，删除后面所有和当前节点 val 相同的节点
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* p = cur;
            while (p->next != nullptr) {
                if (p->next->val == cur->val) {
                    ListNode* tmp = p->next;
                    p->next = p->next->next;
                    delete tmp;
                } else {
                    p = p->next;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};

