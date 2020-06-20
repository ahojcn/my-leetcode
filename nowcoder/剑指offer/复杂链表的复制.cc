// https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&&tqId=11178&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr) return nullptr;

        // 复制每一个节点，使得复制后的节点都在当前节点的下一个节点
        RandomListNode *p = pHead;
        while (p != nullptr) {
            RandomListNode *cloneNode = new RandomListNode(p->label);
            RandomListNode *nextNode = p->next;
            p->next = cloneNode;
            cloneNode->next = nextNode;
            p = nextNode;
        }

        // 复制随机指针
        p = pHead;
        while (p != nullptr) {
            RandomListNode *cloneNode = p->next;
            if (p->random != nullptr) {
                cloneNode->random = p->random->next;
            }
            p = cloneNode->next;
        }

        // 重新连接链表
        p = pHead;
        RandomListNode *cloneHead = p->next;
        while (p->next != nullptr) {
            RandomListNode *tmp = p->next;
            p->next = tmp->next;
            p = tmp;
        }
        return cloneHead;
    }
};

