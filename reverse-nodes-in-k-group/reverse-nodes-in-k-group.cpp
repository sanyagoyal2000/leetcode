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
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != tail) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        
        for (int i = 0; i < k; i++) {
            if (!ptr) return head;
            ptr = ptr->next;
            
        }
        ListNode* tmp = reverse(head, ptr);
        head->next = reverseKGroup(ptr, k);
        return tmp;
    }
};