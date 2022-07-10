#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertattail(node* &head,int d)

{   node *n=new node(d);
    node *temp=head;
    if (head==NULL)
    {
        head=n;
        return ;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;


}
void insertathead(node * &head,int d)
{

        node *n=new node(d);
        n->next=head;
        head=n;


}
void print(node*head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void deleteAthead(node *&head)
{
    node *todelete=head;
    head=head->next;
    delete head;
}
void delete_link(node* &head,int d)

{
    if(head==NULL){
        return ;
    }
    if(head->next==NULL)
    {
        deleteAthead(head);
        return;
    }
        node *temp=head;

        while(temp->next->data!=d)
        {
            temp=temp->next;
        }
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
}
node *reversenode(node* &head)
{
    node *prev=NULL,curr=head,nextptr;
    while(curr!=NULL)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}
int main()

{   node *head=NULL;
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertathead(head,6);
    insertathead(head,7);
    print(head);
}
