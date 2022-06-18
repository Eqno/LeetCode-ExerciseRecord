// https://leetcode.cn/problems/4ueAj6/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr)
        {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }
        for (Node* p=head; p; p=p->next)
        {
            if (p->next == head || p->val<=insertVal && p->next->val>=insertVal || p->val>p->next->val && (p->val<=insertVal || p->next->val>=insertVal))
            {
                Node* node = new Node(insertVal, p->next);
                p->next = node;
                break;
            }
        }
        return head;
    }
};