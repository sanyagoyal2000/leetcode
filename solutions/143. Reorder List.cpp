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
    ListNode* reverse(ListNode* head) {
         if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* small = reverse(head->next);
        head -> next -> next = head;
        head -> next = NULL;
        return small;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* revHead = reverse(slow);
        ListNode* temp1 = head;
        ListNode* temp2 = revHead;
        while(temp1 && temp1!=revHead && temp2!=NULL){
            ListNode* nx1 = temp1 -> next;
            ListNode* nx2 = temp2 -> next;
            temp1 -> next = temp2;
            temp2 -> next = nx1;
            temp1 = nx1;
            temp2 = nx2;
        }
    }
};
