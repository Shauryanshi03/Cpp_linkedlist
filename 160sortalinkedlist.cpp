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

Node* sortlist(Node* head){
    int zerocount=0;
    int onecount=0;
    int twocount=0;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zerocount++;
        }
        else if(temp->data==1){
            onecount++;
        }
        else if(temp->data==2){
            twocount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        
        if(zerocount!=0){
        temp->data=0;
        zerocount--;
        }
        else if(onecount!=0){
            temp->data=1;
            onecount--;
        }
        else if(twocount!=0){
            temp->data=2;
            twocount--;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(0);
    head->next->next=new Node(2);
    head->next->next->next=new Node(1);
    head->next->next->next->next=new Node(0);
    head->next->next->next->next->next=new Node(2);

    cout<<"before sorting : ";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    head=sortlist(head);
    cout<<endl<<"after sorting : ";
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}

/*APPROACH 2

void insertattail(Node* &tail,Node* curr){
     tail->next=curr;
     tail=curr;
}

Node* sortlist(Node* head){
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node* twohead=new Node(-1);
    Node* twotail=twohead;

    Node* curr=head;
    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            insertattail(zerotail,curr);
        }
        else if(value==1){
            insertatatail(onetail,curr);
        }
        else if(value==1){
            insertattail(twotail,curr);
        }
        curr=curr->next;
    }
    //merging
    if(onehead->next!=NULL){
    zerotail->next=onehead->next;
    }
    else{
    zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;

    //setup head
    head=zerohead->next;

    //delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

*/    