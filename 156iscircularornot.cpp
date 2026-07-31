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

bool iscircular(Node* head){
    
    if(head==NULL){
        return true;
     }

     Node* temp=head->next;

     while(temp!=NULL && temp!=head){
        temp=temp->next;
     }

     if(temp==head){
        return true;
     }

     return false;

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

    if (iscircular(head)){
         cout<<"linked list is circular"<<endl;
    }
    else{
        cout<<"linked list is not circular"<<endl;
    }

    return 0;
}

