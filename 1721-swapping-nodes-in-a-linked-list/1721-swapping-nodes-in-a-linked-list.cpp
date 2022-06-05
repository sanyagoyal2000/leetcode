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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *begin;
        ListNode *slow=head ,*fast=head;
        
        for(int cnt=1;cnt<=k and fast!=NULL;cnt++){
            begin=fast;
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        int nk=slow->val;
        slow->val=begin->val;
        begin->val=nk;
        return head;
        
    }
};