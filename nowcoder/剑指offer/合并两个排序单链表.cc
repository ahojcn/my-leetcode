// https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        ListNode *tmpHead = new ListNode(-1);
        ListNode *p = tmpHead;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        if (p2) p->next = p2;
        if (p1) p->next = p1;

        p = tmpHead->next;
        delete tmpHead;
        return p;
    }
};



/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;

        if (pHead1->val < pHead2->val) {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        } else {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
//        return pHead1->val < pHead2->val ? Merge(pHead1->next, pHead2) : Merge(pHead1, pHead2->next);
    }
};
