/*
problem:
    给你一个链表数组，每个链表都已经按升序排列。
    请你将所有链表合并到一个升序链表中，返回合并后的链表。
example:
    输入：lists = [[1,4,5],[1,3,4],[2,6]]
    输出：[1,1,2,3,4,4,5,6]
    解释：链表数组如下：
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    将它们合并到一个有序链表中得到。
    1->1->2->3->4->4->5->6
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
    #define p pair <int, ListNode *>
    class Cmp { public: bool operator ()(const p &a, const p &b) { return a.first>b.first; } };
    priority_queue <p, vector <p>, Cmp> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr, *ans = nullptr;
        for (auto i: lists) if (i) q.push({i->val, i});
        for (bool start=true; q.size(); )
        {
            ListNode *node = q.top().second;
            if (start) ans = res = node, start = false;
            else res->next = node, res = res->next;
            node = node->next; q.pop();
            if (node) q.push({node->val, node});
        }
        return ans;
    }
};