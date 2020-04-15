// https://leetcode-cn.com/problems/intersection-of-two-linked-lists

// 1. 暴力 152 ms	18.1 MB
// 时间O(A + B)  空间O(A)
// 走一遍 A，把走过的节点保存下来
// 再走一遍 B，如果碰到了之前走过的，返回这个节点，如果走完都没有返回空
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        set<ListNode*> s;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa) {
            s.insert(pa);
            pa = pa->next;
        }
        while (pb) {
            if (s.find(pb) != s.end()) {
                return pb;
            }
            pb = pb->next;
        }
        return nullptr;
    }
};

// 2. 双指针浪漫法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headB || !headA) return nullptr;

        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa != pb) {
            pa = (pa == nullptr ? headB : pa->next);
            pb = (pb == nullptr ? headA : pb->next);
        }
        return pa;
    }
};