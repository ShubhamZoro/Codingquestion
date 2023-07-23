using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList*curr=head;
  LinkedList*prev=NULL;
  LinkedList*nptr;
  while(curr!=NULL){
    nptr=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nptr;
  }
  return prev;
}
