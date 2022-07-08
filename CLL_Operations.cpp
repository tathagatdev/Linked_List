//  Circular Linked List 
#include<iostream>
using namespace std;
class node{
   public:
   int data;
   node *next;
    node(int val){
        data=val;
        next=NULL;
    }
}*head;
void CLL_Create(int n){
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
        temp=NewNode;
        
    }
    temp->next=head;
    cout<<"Ciircular Linked List Created Sucessfully"<<endl;
}
void CLL_InsertAtHead(int val){
    node *n=new node(val);
    node *ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=n;
    n->next=head;
    head=n;
    
}
void CLL_InsertAtTail(int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
    }
     node *ptr=head;
     while(ptr->next!=head){
         ptr=ptr->next;
     }
     ptr->next=n;
     n->next=head;
    
    
}
void CLL_Display(){
    node *ptr=head;
    
    if(head==NULL){
        cout<<"Linked list is empty";
    }
    cout<<"Displaying Linked List:"<<endl;
    cout<<ptr->data<<"->";
    ptr=ptr->next;
    while(ptr!=head){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
    
}
void CLL_InsertAtPos(int val,int pos)
{
    node *n=new node(val);
    node *ptr=head;
    int count=1;
    while(ptr->next!=head and count<=pos-1 )
    {
        ptr=ptr->next;
        count++;
    }
     n->next=ptr->next;
     ptr->next=n;
    
     
}
void CLL_DeleteHead(){
    node *ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=head->next;
    delete head;
    head=ptr->next;
}
void CLL_DeleteTail(){
    node *p=head;
    node *q=head->next;
    while(q->next!=head){
        q=q->next;
        p=p->next;
      }
      p->next=q->next;
      delete q;
}
void CLL_DeleteIntermediate(int key){
    node *p=head;
    node *q=head->next;
    while(q->data!=key  and q->next!=head){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
      delete q;
    
}
bool CLL_Search(int key){
    node *p=head;
    if(p->data==key){
        return true;
    }
    p=p->next;
    while(p!=head){
        if(p->data==key){
            return true;
        }
        p=p->next;
    }
    return false;
}
int main(){
    CLL_Create(3);
    CLL_Display();
    CLL_InsertAtHead(0);
    CLL_Display();
    CLL_InsertAtTail(4);
    CLL_Display();
    CLL_InsertAtPos(100,2);
    CLL_Display();
    CLL_DeleteHead();
    CLL_Display();
    CLL_DeleteTail();
    CLL_Display();
    CLL_DeleteIntermediate(100);
    CLL_Display();
    cout<<CLL_Search(1);
}
