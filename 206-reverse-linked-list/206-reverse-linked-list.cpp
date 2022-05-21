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
    ListNode* reverseList(ListNode* head) {
        //recursive
        if(head==NULL or head->next==NULL)return head;
        ListNode *nhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return nhead;
       //iterative
        /*
       ListNode *temp=NULL,*prev=NULL ,*curr=head;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    */
    }
};