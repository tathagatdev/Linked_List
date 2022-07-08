//  Doubly Linked List Operations

#include<iostream>
using namespace std;
class node{
   public:
   int data;
   node *next;
   node *prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
}*head;
void DLL_Create(int n){
    int val;
    node *temp;
    cout<<"Enter value for 1 node:"<<" ";
    cin>>val;
    head=new node(val);
    if(head==NULL){
        cout<<"Memory cannot be allocated";
    }
    temp=head;
    for(int i=2;i<=n;i++){
        cout<<"Enter data for"<<" "<<i<<" "<<"node"<<":"<<" ";
        cin>>val;
        node *NewNode=new node(val);
        temp->next=NewNode;
        NewNode->prev=temp;
        temp=NewNode;
        
    }
    cout<<"Doubly Linked List Created Sucessfully"<<endl;
    
}
void DLL_InsertAtHead(int val){
    node *n=new node(val);
     n->next=head;
     n->prev=NULL;
     head=n;
}
void DLL_InsertAtTail(int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
    }
     node *ptr=head;
     while(ptr->next!=NULL){
         ptr=ptr->next;
     }
     ptr->next=n;
     n->next=NULL;
     n->prev=ptr;
    
    
}
void DLL_Display(){
    node *ptr=head;
    if(head==NULL){
        cout<<"Linked list is empty";
    }
    cout<<"Displaying Linked List:"<<endl;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
    
}
void DLL_InsertAtPos(int val,int pos)
{
    node *n=new node(val);
    node *ptr=head;
    int count=1;
    while(ptr->next!=NULL and count<=pos-1 )
    {
        ptr=ptr->next;
        count++;
    }
     ptr->next->prev=n;
     n->next=ptr->next;
     ptr->next=n;
     n->prev=ptr;
     
}
void DLL_DeleteHead(){
    node *ptr=head;
    head=head->next;
    head->prev=ptr;
    delete ptr;
}
void DLL_DeleteTail(){
    node *p=head;
    node *q=head->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
      }
      q->prev->next=NULL;
      p->next=NULL;
      delete q;
}
void DLL_DeleteIntermediate(int key){
    node *p=head;
    node *q=head->next;
    while(q->data!=key  and q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    q->next->prev=p;
    p->next=q->next;
    delete q;
    
}
bool DLL_Search(int key){
    node *p=head;
    while(p!=NULL){
        if(p->data==key){
            return true;
        }
        p=p->next;
    }
    return false;
    
}
int main()
{  DLL_Create(5);
   DLL_Display();
   DLL_InsertAtHead(0);
   DLL_Display();
   DLL_InsertAtTail(6);
   DLL_Display();
   DLL_InsertAtPos(100,3);
   DLL_Display();
   DLL_DeleteHead();
   DLL_Display();
   DLL_DeleteTail();
   DLL_Display();
   DLL_DeleteIntermediate(100);
   DLL_Display();
   cout<<DLL_Search(100);
  
  
    return 0;
}
