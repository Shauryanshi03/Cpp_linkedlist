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

Node* floydDetectLoop(Node* head){
    if(head==NULL)
    return NULL;

    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getstartingnode(Node* head){
    if(head==NULL)
    return NULL;

    Node* intersection=floydDetectLoop(head);
    if(intersection==NULL)
    return NULL;
    Node* slow=head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

Node* removeloop(Node* head){
    if(head==NULL)
    return NULL;

    Node* startofloop=getstartingnode(head);
    if(startofloop==NULL)
    return head;
    Node* temp=startofloop;

    while(temp->next!=startofloop){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
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

    //create loop
    fifth->next=third;

    //detect loop
    if (floydDetectLoop(head))
    cout<<"Loop Detected"<<endl;
    else
    cout<<"No Loop"<<endl;

    //remove loop
    head=removeloop(head);

    //check again
    if(floydDetectLoop(head))
    cout<<"Loop Still Exists"<<endl;
    else
    cout<<"Loop Removed"<<endl;

    //printing
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}