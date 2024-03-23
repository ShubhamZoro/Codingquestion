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
    ListNode*reverse(ListNode*slow){
        ListNode*curr=slow;
        ListNode*prev=NULL;
        ListNode*nptr;
        while(curr!=NULL){
            nptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nptr;
        }
        return prev;
    }

    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*dummy=new ListNode(0);
        ListNode*curr=dummy;
        bool c=true;
        while(l1 && l2){
            if(c){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
            c=!c;
        }
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return dummy->next;
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*temp=NULL;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        slow=reverse(slow);
        head=merge(head,slow);
       
    }   
};
