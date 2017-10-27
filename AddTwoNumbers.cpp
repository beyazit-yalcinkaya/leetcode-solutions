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
    bool longer(ListNode* l1, ListNode* l2)
    {
        int i = 0, j = 0;
        for (; l1; i++) l1 = l1 -> next;
        for (; l2; j++) l2 = l2 -> next;
        if (i >= j) return true;
        return false;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out;
        ListNode* helper;
        ListNode* other;
        ListNode* temp;
        if (longer(l1, l2))
        {
            out = l1;
            helper = l1;
            other = l2;
        }
        else
        {
            out = l2;
            helper = l2;
            other = l1;
        }
        int inhand = 0;
        while (other)
        {
            helper -> val += other -> val + inhand;
            inhand = helper -> val / 10;
            helper -> val %= 10; 
            temp = helper;                       
            helper = helper -> next;
            other = other -> next;
        }
        while (inhand)
        {
            if (not helper)
            {
                ListNode* newnode = new ListNode(0);
                newnode -> val = inhand;
                while (temp -> next != NULL) temp = temp -> next;
                temp -> next = newnode;
                inhand = 0;
            }
            else
            {
                helper -> val += inhand;
                inhand = helper -> val / 10;
                helper -> val %= 10; 
                temp = helper;                       
                helper = helper -> next;  
            }
        }
        return out;        
    }
};