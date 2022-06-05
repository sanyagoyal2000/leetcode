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
    ListNode* swapPairs(ListNode* head) {
       if(head == NULL || head-> next == NULL)  // if list contain 0 nodes or a single node return head
            return head;
        
        ListNode* temp = head;    // temporary pointer so that we don't loose reference to head
        
        while(temp)        // while temp != NULL
        {
            if(temp->next != NULL)       
            {
			   // if list contain odd no of nodes than at last node the temp->next,
			   //will be pointing to null and the code crashes, as there is no other node,
			   // to perform swap opearation
                swap(temp->val, temp->next->val);    // swap with the adjacent node
                temp = temp->next->next;                 //incrementing pointer with 2 step
            }
				else    // break because last pair of list is odd 
					break;
        }
        
        return head;    
    }
};