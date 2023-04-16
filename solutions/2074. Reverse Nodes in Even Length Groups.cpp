            curr=temp;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode *prev=dummy;
        for(int cnt=1;cnt<1e5 and head;cnt++){
            ListNode *tail=head;
            ListNode *nexthead;
            int cntnodes=1;
            while(cntnodes<cnt and tail and tail->next){
                tail=tail->next;
                cntnodes++;
            }
            nexthead=tail->next;
            if((cntnodes%2) ==0){
                tail->next=NULL;
                prev->next=reverse(head);
                prev=head;
                head->next=nexthead;
                head=nexthead;
                
            }
            else{
                prev=tail;
                head=nexthead;
            }
        }
        
        return dummy->next;
    }
};
​
​
