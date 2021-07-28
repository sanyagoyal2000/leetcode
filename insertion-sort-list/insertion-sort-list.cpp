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
    ListNode* insertionSortList(ListNode* head) {
     if(!head || head->next==NULL) return head;
        ListNode* temp, *curr = head->next, *prev, *node;
        head->next = NULL;
        
        while(curr){
            node = curr;
            curr = curr->next;
            temp = head;
            while(temp && temp->val < node->val){
                prev = temp;
                temp = temp->next;
            }
            if(temp==head){
                node->next = temp;
                head = node;
            }else{
                prev->next = node;
                node->next = temp;
            }
        }
        return head;   
    }
};