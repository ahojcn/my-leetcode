// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

// 1.
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {

        ListNode* f = head;
        while (k-- && f) {
            f = f->next;
        }

        ListNode* s = head;
        while (f) {
            s = s->next;
            f = f->next;
        }

        return s;
    }
};
