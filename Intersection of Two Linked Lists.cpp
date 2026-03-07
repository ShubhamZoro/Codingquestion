/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *>A;
        
        while(headA!=NULL){
            A.insert(headA);
            headA=headA->next;
        }
        while(headB!=NULL){
            if(A.find(headB)!=A.end()){
                return headB;
            }

            headB=headB->next;
        }

        return NULL;
    }
};
---------------------------------------
// constant space
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode* A = headA;
        ListNode* B = headB;

        while (A != B) {
            A = (A != nullptr) ? A->next : headB;
            B = (B != nullptr) ? B->next : headA;
        }

        return A; 
    }
};
