// Reversing a linked list
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
void SLL_Reverse(){
    node *prev=NULL;
    node *curr=head;
    node *nextptr;
    while(curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    head=prev;
    
}
int main()
{
SLL_Create(5);
SLL_Display();
SLL_Reverse();
SLL_Display();
cout<<endl;
    }