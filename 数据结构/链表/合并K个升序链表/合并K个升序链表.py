"""
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
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from queue import PriorityQueue
class Node:
    def __init__(self, node=None):
        self.node = node
        self.key = node.val
    def __lt__(self, other):
        return self.key < other.key
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        q = PriorityQueue()
        res = None
        ans = None
        for i in lists:
            if i:
                q.put(Node(i))
        s = True
        while q.qsize():
            node = q.get().node
            if s:
                ans = node
                res = node
                s = False
            else:
                res.next = node
                res = res.next
            node = node.next
            if node:
                q.put(Node(node))
        return ans