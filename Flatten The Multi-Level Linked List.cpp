#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

    class Node {
      public:
        T data;
        Node<T> *next;
        Node<T> *child;

        Node(T data) {
            this->data = data;
            next = NULL;
            child = NULL;
        }
    };

*****************************************************************/

Node<int> *flattenMultiLinkedList(Node<int> *head) {
    // Write your code here.
    queue<Node<int>*>q;
    q.push(head);
    Node<int>*curr;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        while(curr!=NULL){
            if(curr->child){
                q.push(curr->child);
                curr->child=NULL;
            }
            if (!curr->next && !q.empty()) {
            curr->next = q.front();
            q.pop();
        }
            curr=curr->next;
        }
        
        
    }
    return head;

}
