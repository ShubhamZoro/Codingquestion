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
    ListNode*getkth(ListNode*gprev,int k){
        ListNode*curr=gprev;
        while(curr!=NULL &&k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*gprev=dummy;
        while(1){
            ListNode*kth=getkth(gprev,k);
            if(kth==NULL){
                break;
            }
            ListNode*gnext=kth->next;
            ListNode*prev=kth->next;
            ListNode*curr=gprev->next;
            ListNode*nptr;
            while(curr!=gnext){
                nptr=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nptr;
            }
            curr=gprev->next;
            gprev->next=kth;
            gprev=curr;
            
        }
        return dummy->next;
    }
};
