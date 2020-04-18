// https://leetcode-cn.com/problems/linked-list-cycle-ii

// 1. 找，就硬找
// 保存已经走过的 node，如果某次走到的 node 是之前走过的，那就是环形入口
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        
        set<ListNode*> s;
        ListNode* cur = head;
        while (cur) {
            if (s.find(cur) != s.end()) {
                return cur;
            }
            s.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};

// 2. 快慢指针
// 当快指针、慢指针相遇 慢指针走了 x + y
// 快指针走了 x + y + z + y
// 得到 z = x
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode* s = head;
        ListNode* f = head;
        while (s && f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                f = head;
                while (s != f) {
                    s = s->next;
                    f = f->next;
                }
                return f;
            }
        }
        return nullptr;
    }
};