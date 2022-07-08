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
void SLL_Create(int n){
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
    cout<<"Singly Linked List Created Sucessfully"<<endl;
    
}
void SLL_Display(){
    node *ptr=head;
    if(head==NULL){
        cout<<"Linked list is empty";
    }
    cout<<"Displaying Linked List:"<<endl;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    
}
void SLL_CreateCycle(int pos) //Make pt1 at posn and pt2 at last node and then pt2->next=pt1
{
    node *p=head;
    node *q;
    int count=1;
    while(p->next!=NULL){
        if(count==pos){
            q=p;
        }
        p=p->next;
        count++;
    }
    p->next=q;
}
bool SLL_DetectCycle()
{
    node *fast=head;
    node *slow=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void SLL_RemoveCycle(){
    node *fast=head;
    node *slow=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);
    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}
int main(){
    SLL_Create(5);
    SLL_Display();
    SLL_CreateCycle(3);
    cout<<endl;
    cout<<SLL_DetectCycle();
    SLL_RemoveCycle();
    cout<<endl;
    cout<<SLL_DetectCycle();
    return 0;
}
    
