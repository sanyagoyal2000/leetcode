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
    ListNode* partition(ListNode* head, int x) {
        ListNode * headref = new ListNode();
        ListNode * prev = headref, *curr = head;
        
        //take the lesser nodes first;
        while(curr)
        {
            if(curr->val < x)
            {
                prev->next = new ListNode(curr->val);
                prev = prev->next;
            }
            curr = curr->next;
        }
        // take equal or greater nodes 
        curr = head;
        while(curr)
        {
            if(curr->val >= x)
            {
                prev->next = new ListNode(curr->val);
                prev = prev->next;
            }
            curr = curr->next;
        }
        return headref->next;
        
    }
};