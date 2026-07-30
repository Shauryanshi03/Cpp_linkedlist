#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for data : "<<value<<endl;
    }
};

void insertathead(Node* &head,int d){

    //create new node
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertatposition(Node* &tail,Node* &head,int position,int d){

    //insert at start
    if(position==1){
        insertathead(head,d);
        return;
    }
    Node* temp=head;
    int count=1;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    //insert at last
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }

    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}

void deletenode(int position,Node* &head){
   
    //deleting start node
    if(position==1){
       
        Node* temp=head;
        head=head->next;

        //memory free
        temp->next=NULL;
        delete temp;
    }

    //deleting any else node
    else{

        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){

    //created a new node
    Node* node1=new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    //head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);

    insertathead(head,12);
    print(head);

    insertathead(head,15);
    print(head);

    insertattail(tail,20);
    print(head);

    insertatposition(tail,head,3,22);
    print (head);

    deletenode(1,head);
    print(head);

    return 0;
}