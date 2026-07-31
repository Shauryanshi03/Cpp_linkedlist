#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

int getlength(Node* head){

    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

Node* middle(Node* head){
    int len=getlength(head);
    int ans=(len/2);

    Node* temp=head;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
}

int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    Node* ans=middle(head);

    cout<<"Middle mode : "<<ans->data<<endl;

    return 0;
}

/*(optimised solution)

Node* getmiddle(Node* head){

if(head==NULL || head->next==NULL)
return NULL;

if(head->next->next==NULL)
return head->next;

Node* slow=head;
Node* fast=head->next;

while(fast!=NULL){
fast=fast->next;

if(fast!=NULL){
fast=fast->next;
}

slow=slow->next;
}

return slow;
}

*/