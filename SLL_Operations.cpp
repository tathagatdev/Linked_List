//  Singly Linked List Operations

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
void SLL_InsertAtHead(int val){
    node *n=new node(val);
     n->next=head;
     head=n;
}
void SLL_InsertAtTail(int val){
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
void SLL_InsertAfterNode(int val,int key)
{
    node *n=new node(val);
    node *ptr=head;
    while(ptr!=NULL and ptr->data!=key)
    {
        ptr=ptr->next;
    }
    
    n->next=ptr->next;
    ptr->next=n;
}
void SLL_InsertBeforeNode(int val,int key){
    node *n=new node(val);
    node *p=head;
    node *q=head->next;
    while(q->data!=key and q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next=n;
    n->next=q;
}
void SLL_DeleteHead(){
    node *ptr=head;
    head=head->next;
    delete ptr;
}
void SLL_DeleteTail(){
    node *p=head;
    node *q=head->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
      }
      p->next=NULL;
      delete q;
}
void SLL_DeleteIntermediate(int key){
    node *p=head;
    node *q=head->next;
    while(q->data!=key  and q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    delete q;
    
}
int SLL_Count(){
    int count=0;
    node *p=head;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    return count;
    
}
bool SLL_Search(int key){
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
{
    int key, value,n,ch;
    int ch1;
    
  do{
   
    cout<<" Singly LinkedList Operation Menu \n";
    cout<<"Enter choice \n";
    cout<<" 0: Create n Nodes  \n";
    cout<<" 1: Insert At Head  \n";
    cout<<" 2:  Insert At Tail \n";
    cout<<" 3: Insert After a Node \n";
    cout<<" 4: Insert Before a Node \n";
    cout<<" 5: Delete at the Beginning \n";
    cout<<" 6: Delete at the end \n";
    cout<<" 7: Delete Intermediate node \n";
    cout<<" 8: Display elements of the list \n";
    cout<<" 9: Search a element \n";
   
    cin>>ch;
    switch(ch)
    {
        case 0:  cout<<"How Many Nodes you want to create \n";
                cin>>n;;
                 SLL_Create(n);
                 break;
        case 1:  cout<<"Enter value to be entered  \n";
                 cin>>value;
                 SLL_InsertAtHead(value);
                 SLL_Display();
                break;
        case 2: cout<<"Enter value to be entered  \n";
                 cin>>value;
                 SLL_InsertAtTail(value);
                 SLL_Display();
                break;
        case 3: cout<<"Enter value to be entered  \n";
                 cin>>value;
                cout<<"Enter  the key";
                cin>>key;
                SLL_InsertAfterNode(value,key);
                SLL_Display();
                break;
        case 4: cout<<"Enter value to be entered  \n";
                cin>>value;
                cout<<"Enter the key";
                cin>>key;
                SLL_InsertBeforeNode(value,key);
                SLL_Display();
                break;
        case 5:  cout<<"Deleting Head Node";
                 SLL_DeleteHead();
                 SLL_Display();
                 break;
        case 6: cout<<"Deleting Tail Node";
                SLL_DeleteTail;
                SLL_Display();
                break;
        case 7: cout<<"Enter key of the node to be deleted";
                cin>>key;
                SLL_DeleteIntermediate(key);
                SLL_Display();
                break;
                
        case 8: cout<<" Traversing \n";
                SLL_Display();
                break;
        case 9:  cout<<"Enter element to be searched";
                 cin>>key;
                 SLL_Search(key);
                 break;
        default:  cout<<" WRONG CHOICE !!!";
                  break;
    }
    cout<<"Want to continue with other operations?   \n  1-Yes  \n 0-No";
    cin>>ch1;
  }while(ch1==1);
  
    return 0;
}