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

Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
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

    head=reverse(head);

    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}

/*(recursive solution 1)

void reverse1(Node* &head,Node* curr,Node*prev){

    if(curr==NULL){
        head=prev;
        return;
    }

    Node* forward=curr->next;
    reversell(head,forward,curr);
    curr->next=prev;

}*/


/*(recursive solution 2)

Node* reverse(Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* head2=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;

    return head2;

*/
