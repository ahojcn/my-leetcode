// https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tags=&title=&diffculty=0&judgeStatus=0&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *s = pHead, *f = pHead;
        while (s && f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                f = pHead;
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

