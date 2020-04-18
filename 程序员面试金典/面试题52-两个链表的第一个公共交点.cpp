// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/submissions/

// 1. 你走过我来时的路
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa != pb) {
            pa = (pa == nullptr ? headB : pa->next);
            pb = (pb == nullptr ? headA : pb->next);
        }
        return pa;
    }
};