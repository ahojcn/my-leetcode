// https://leetcode-cn.com/problems/middle-of-the-linked-list/

// 1. 快慢指针解法
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;

        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }

        return s;
    }
};