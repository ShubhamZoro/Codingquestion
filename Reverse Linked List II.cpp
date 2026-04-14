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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*curr=head;
        ListNode*prev=NULL;
        for(int i=0;i<left-1;i++){
            prev=curr;
            curr=curr->next;
        }
        ListNode*connection=prev;
        ListNode*temp=NULL;
        ListNode*an=curr;
        while(right-left+1>0){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            right--;
        }
        
        if(connection){
            connection->next=prev;
        }
        else{
            head=prev;
        }
        an->next=curr;
        return head;
        
    }
};
