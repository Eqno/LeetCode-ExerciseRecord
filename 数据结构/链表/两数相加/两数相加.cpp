/*
problem:
    给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
example:
    输入：l1 = [2,4,3], l2 = [5,6,4]
    输出：[7,0,8]
    解释：342 + 465 = 807.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool flag = false, start = true;
        ListNode *l3, *p;
        while (l1 || l2)
        {
            int sum = flag;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            flag = sum >= 10, sum %= 10;
            ListNode *node = new ListNode(sum);
            if (start)
            {
                p = l3 = node;
                start = false;
            }
            else
            {
                p->next = node;
                p = p->next;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (flag) p->next = new ListNode(1);
        return l3;
    }
};