#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};

void insertattail(Node* &head,Node* &tail,int d){
    Node* newnode=new Node(d);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}

Node* clone(Node* head){
    Node* clonehead= NULL;
    Node* clonetail=NULL;

    Node* temp=head;

    while(temp!=NULL){
        insertattail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }

    unordered_map<Node*, Node*>oldtonew;

    Node* originalnode=head;
    Node* clonenode=clonehead;

    while(originalnode!=NULL && clonenode!=NULL){
        oldtonew[originalnode]=clonenode;
        originalnode=originalnode->next;
        clonenode=clonenode->next;
    }
    originalnode=head;
    clonenode=clonehead;

    while(originalnode!=NULL){
        clonenode->random=oldtonew[originalnode->random];
        originalnode=originalnode->next;
        clonenode=clonenode->next;
    }
    return clonehead;
}

int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);

    head->next=second;
    second->next=third;
    third->next=fourth;

    head->random=third;
    second->random=head;
    third->random=fourth;
    fourth->random=second;

    Node* clonehead=clone(head);

    cout<<"original list : "<<endl;
    Node* temp=head;
    while(temp!=NULL){
        cout<<"data : "<<temp->data;
        if(temp->random)
        cout<<"random : "<<temp->random->data;
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl<<"cloned list : "<<endl;
    temp=clonehead;
    while(temp!=NULL){
        cout<<"data : "<<temp->data;
        if(temp->random)
        cout<<"random : "<<temp->random->data;
        cout<<endl;
        temp=temp->next;
    }
    return 0;
}

/*APPROACH 2

//step 1
Node* copy(Node* head){
Node* clonehead=NULL;
Node* clonetail=NULL;

Node* temp=head;
while(temp!=NULL){
inserattail(clonehead,clonetail,temp->data);
temp=temp->next;
}

//step 2
Node* originalnode=head;
Node* clonenode=clonehead;

while(originalnode!=NULL && clonenode!=NULL){
Node* next=originalnode->next;
originalnode->next=clonenode;
originalnode=next;

next=clonenode->next;
clonenode->next=originalnode;
clonenode=next;
}

//step 3
Node* curr=head;
while(temp!=NULL){
if(temp->next!=NULL){
if(temp->random!=NULL){
temp->next->random=temp->random->next;
}
else{
temp->next=temp->random;
}
}
temp=temp->next->next;
}

//step 4
originalnode=head;
clonenode=clonehead;

while(originalnode!=NULL && clonenode!=NULL){
originalnode->next=clonenode->next;
originalnode=original->next;

if(originalnode!=NULL){
clonenode->next=originalnode->next;
}
clonenode=clonenode->next;
}

//step 5
return clonehead;

}
*/