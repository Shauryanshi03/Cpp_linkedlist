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

Node* sortedlist(Node* head){
    if(head==NULL)
    return NULL;

    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            Node* next_next=curr->next->next;
            Node* nodetodelete=curr->next;
            delete(nodetodelete);
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

int main(){
     Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(20);
    Node* fourth=new Node(30);
    Node* fifth=new Node(30);
    Node* sixth=new Node(30);
    Node* seventh=new Node(40);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;

    head=sortedlist(head);

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}