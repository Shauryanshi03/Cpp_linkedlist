#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;

    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory is free for value : "<<value<<endl;
    }
};

void insertnode(Node* &tail,int element,int d){

    //empty list
    if(tail==NULL){
        Node* newnode=new Node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        //nonempty list
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void print(Node* tail){
    Node* temp=tail;

    //empty list
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    do{
       cout<<tail->data<<" ";
       tail=tail->next;
    } while(tail!=temp);
    cout<<endl;
}

void deletenode(Node* &tail,int value){
    //emptylist
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    //nonempty
    else{
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;

        //1 node list
        if(curr==prev){
            tail=NULL;
        }

        //>=2 node list
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}

int main(){
    Node* tail=NULL;
    Node* head=NULL;

    insertnode(tail,5,3);
    print(tail);

    insertnode(tail,3,5);
    print(tail);

    insertnode(tail,5,7);
    print(tail);

    insertnode(tail,7,9);
    print(tail);

    insertnode(tail,5,6);
    print(tail);

    deletenode(tail,3);
    print(tail);

    deletenode(tail,5);
    print(tail);

    return 0;
}