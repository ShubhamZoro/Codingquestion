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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*curr=list1;
        int count=1;
        while(list1!=NULL){
            if(count==a){
                ListNode*temp=list1;
                for(int i=0;i<b-a+1;i++){
                    temp=temp->next;
                }
                if(temp==NULL){
                    list1->next=list2;
                }
                else{
                    list1->next=list2;
                    while(list2->next!=NULL){
                        list2=list2->next;
                    }
                    list2->next=temp->next;
                }
                break;
            }
            list1=list1->next;
            count++;
        }
        return curr;
    }
};
