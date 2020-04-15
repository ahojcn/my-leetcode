// https://leetcode-cn.com/problems/linked-list-cycle/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode* s = head;
        ListNode* f = head;
        while (f && s && f->next) {
            f = f->next->next;
            s = s->next;
            if (s == f) {
                return true;
            }
        }
        return false;
    }
};
