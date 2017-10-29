/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (not l1 and not l2) return l1;
        else if (not l1) return l2;
        else if (not l2) return l1;
        ListNode *a, *b, *out, *prea = nullptr, *preb = nullptr;
        if (l1 -> val <= l2 -> val) out = a = l1, b = l2;
        else out = a = l2, b = l1;
        while (a and b)
        {
            if (a -> val <= b -> val)
            {
                prea = a;
                a = a -> next;
            }
            else
            {
                preb = b;
                b = b -> next;
                prea -> next = preb;
                preb -> next = a;
                a = preb;
            }
        }
        if (b)
        {
            prea -> next = b;
        }
        return out;
    }
};