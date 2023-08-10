**
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode*curr=new ListNode(0);
        ListNode*prev=new ListNode(0);
        ListNode*right=curr;
        ListNode*left=prev;
        
        while(head!=NULL){
            if(head->val>=x){
                right->next=head;
                right=right->next;
            }
            else{
                left->next=head;
                left=left->next;
            }
            head=head->next;
        }
        left->next=curr->next;
        right->next=NULL;
        return prev->next;
    }
};
