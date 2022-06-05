/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head, *fast=head;
        ListNode *prev=NULL;
        if(head==NULL or head->next==NULL)return NULL;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
            
        }
        prev->next=slow->next;
        return head;
    }
};
