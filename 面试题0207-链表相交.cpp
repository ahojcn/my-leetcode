// https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/

// 1. 使用 vector 保存两个链表的节点，然后查找相同的节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> va;
        vector<ListNode*> vb;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa) {
            va.push_back(pa);
            pa = pa->next;
        }
        while (pb) {
            vb.push_back(pb);
            pb = pb->next;
        }

        for (int i = 0; i < va.size(); ++i) {
            for (int j = 0; j < vb.size(); ++j) {
                if (vb[j] == va[i]) {
                    return vb[j];
                }
            }
        }
        return nullptr;
    }
};

// 2. 因为 1 的超出时间，优化一下
// 184 ms	18.2 MB
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> sa;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa) {
            sa.insert(pa);
            pa = pa->next;
        }
        while (pb) {
            if (sa.find(pb) != sa.end()) return pb;
            pb = pb->next;
        }
        return nullptr;
    }
};


// 3. 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa != pb) {
            pa = (pa == nullptr ? headB : pa->next);
            pb = (pb == nullptr ? headA : pb->next);
        }
        return pb;
    }
};
