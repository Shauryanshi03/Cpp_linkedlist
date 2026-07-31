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

Node* kreverse(Node* head,int k){
    if(head==NULL){
        return NULL;
    }

    Node* next=NULL;
    Node* curr=head;
    Node* prev=NULL;
    int count=0;

    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next=kreverse(next,k);
    }
    return prev;
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    
    node1->next=new Node(20);
    node1->next->next=new Node(30);
    node1->next->next->next=new Node(40);
    node1->next->next->next->next=new Node(50);
   
    int k=2;

    head=kreverse(head,k);

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    return 0;
}