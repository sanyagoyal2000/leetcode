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
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head;
        vector<int>arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        reverse(arr.begin(),arr.end());
        temp=head;
        int i=0;
        while(temp!=NULL){
            if(temp->val!=arr[i])return false;
            else{
                temp=temp->next;
                i++;
            }
        }
        return true;
    }
};