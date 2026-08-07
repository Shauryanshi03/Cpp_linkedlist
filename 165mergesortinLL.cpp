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

Node* findmid(Node* head){
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* merge(Node* left,Node* right){
    if(left==NULL)
    return right;

    if(right==NULL)
    return left;

    Node* ans=new Node(-1);
    Node* temp=ans;

    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }

    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    ans=ans->next;
    return ans;
}

Node* mergesort(Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* mid=findmid(head);

    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;

    left=mergesort(left);
    right=mergesort(right);

    Node* result=merge(left,right);
    return result;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(5);
    head->next=new Node(2);
    head->next->next=new Node(8);
    head->next->next->next=new Node(1);
    head->next->next->next->next=new Node(6);

    cout<<"original list : ";
    print(head);

    head=mergesort(head);

    cout<<"sorted list : ";
    print(head);

    return 0;

}