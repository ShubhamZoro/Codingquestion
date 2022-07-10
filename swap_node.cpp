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
 //Input: head = [1,2,3,4]
//Output: [2,1,4,3]
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL||head->next==NULL)
            return head;
        ListNode*dummy=new ListNode();
        ListNode*prev=dummy;
        ListNode*curr=head;
        while(curr!=NULL&&curr->next!=NULL)
        {
            prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;
            prev=curr;
            curr=curr->next;

        }
        return dummy->next;
    }
};
