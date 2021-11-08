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
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        boolean flag = false;
        ListNode l3 = new ListNode(0), p = l3;
        while (l1!=null || l2!=null)
        {
            int sum = flag ? 1 : 0;
            if (l1 != null) sum += l1.val;
            if (l2 != null) sum += l2.val;
            flag = sum >= 10;
            sum %= 10;
            ListNode node = new ListNode(sum);
            p.next = node;
            p = p.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        if (flag) p.next = new ListNode(1);
        return l3.next;
    }
}