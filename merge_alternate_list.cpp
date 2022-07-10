#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

node* alternateMerge(node * root1, node* root2){
    //Complete this function
    node *h,*p;
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;

    h=p=root1;
    root1=root1->next;
    p->next=root2;
    root2=root2->next;
    p=p->next;


    while(root1!=NULL&&root2!=NULL)
    {


            p->next=root1;
            root1=root1->next;
            p=p->next;


            p->next=root2;
            root2=root2->next;
            p=p->next;

    }

    if(root1!=NULL)
    {
        p->next=root1;
    }
    else
    {
        p->next=root2;
    }

    return h;

}


