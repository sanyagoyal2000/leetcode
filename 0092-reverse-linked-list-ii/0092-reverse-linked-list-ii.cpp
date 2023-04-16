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
    ListNode *reverse(ListNode *head){
        if(head==NULL or head->next==NULL)return head;
        ListNode *curr=head;
        ListNode *prev=NULL, *temp=NULL;
        while (curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;  
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode();
        dummy->next=head;
        head=dummy;
        ListNode *curr=head;
        ListNode *prev=dummy;
        int cnt=0;
        if(left==right)return dummy->next;
        while(cnt<left and curr!=NULL){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        
        ListNode *start=curr;
         while(cnt<right and curr!=NULL){
            curr=curr->next;
             cnt++;
        }
        ListNode *tail=curr;
        ListNode *nexthead=tail->next;
        tail->next=NULL;
        prev->next=reverse(start);
        start->next=nexthead;
        return dummy->next;
    }
};