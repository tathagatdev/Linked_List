/*
eg:
k=2
1->2->3->4->5->6
k=2 means ki 1 or 2 ko reverse then 3-4 ko then 5-6 ko
so pehle do ko toh normal iterative method mein jaise kiya waise kardenge
or aage ke liye fn dubara call karenge k+1th se start hoke aage ka reverse hogya 
toh mila: 1 <-2  4-> 3-> 6-> 5  then 1 ke next ko 4 pe point
final ans:
2 1 4 3 6 5 
*/
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){ //constructor
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;

}
//insertion at tail
void insertAtTail(node* &head /*call by ref*/,int val){

    node* n=new node(val);  //creating new node
    
    if(head==NULL){ //if list is empty
        head=n;
        return;
    }

    node* temp=head; //ek temp nam ka pointer banaya to get help in traversing
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head) /*call by value as yahan ll mein kuch modify nhi kar rhe h*/{
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
node* reversek(node* &head,int k){
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    
    int count=0;// to know ki n nodes kahan tak h
    while(curr!=NULL && count<k){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
    //abhi tak mein pehle k node reverse ho chuke ab aage walon ke liye recursively call karna h
    if(nextptr!=NULL){
    head->next=reversek(nextptr,k); //mtlb 1 ko 4 pe point
    }
    return prev;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    int k=2;
    node* newhead=reversek(head,k);
    display(newhead);
}