// https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// 1.
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int count = 0;
        ListNode* cur = head;
        while (cur->next) {
            count++;
            cur = cur->next;
        }

        int ret = 0;
        cur = head;
        while (cur) {
            ret += cur->val * pow(2, count--);
            cur = cur->next;
        }
        return ret;
    }
};

// 2. 由于链表中从高位到低位存放了数字的二进制表示，
// 因此我们可以使用二进制转十进制的方法，在遍历一遍链表的同时得到数字的十进制值。
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int res = 0;
        while (cur) {
            res = res * 2 + cur->val;
            cur = cur->next;
        }
        return res;
    }
};