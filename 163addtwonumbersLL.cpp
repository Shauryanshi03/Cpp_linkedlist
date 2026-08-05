#include<iostream>
#include<vector>
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

void insertattail(Node* &head,Node* &tail,int val){
    Node* temp=new Node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node* add(Node* first, Node* second){
    int carry=0;
    Node* anshead=NULL;
    Node* anstail=NULL;

    while(first!=NULL && second!=NULL){
        int sum=carry+first->data+second->data;
        int digit=sum%10;
        
        insertattail(anshead,anstail,digit);
        carry=sum/10;

        first=first->next;
        second=second->next;
    }

    while(first!=NULL){
        int sum=carry+first->data;
        int digit=sum%10;

        insertattail(anshead,anstail,digit);
        carry=sum/10;

        first=first->next;
    }

    while(second!=NULL){
        int sum=carry+second->data;
        int digit=sum%10;

        insertattail(anshead,anstail,digit);
        carry=sum/10;

        second=second->next;
    }

    while(carry!=0){
        int sum=carry;
        int digit=sum%10;

        insertattail(anshead,anstail,digit);
        carry=sum/10;
    }
    return anshead;
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;

        while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    }
return prev;
}

Node* addtwolist(Node* first, Node* second){
    first=reverse(first);
    second=reverse(second);

    Node* ans=add(first,second);

    ans=reverse(ans);

    return ans;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
     Node* first=new Node(1);
    first->next=new Node(3);
    first->next->next=new Node(5);

    Node* second=new Node(2);
    second->next=new Node(4);
    second->next->next=new Node(6);

    Node* ans=addtwolist(first,second);

    cout<<"Sum = ";
    print(ans);

    return 0;
}

/*APPROACH 2
Node* add(Node* first,Node* second){

int carry=0;
Node* anshead=NULL;
Node* anstail=NULL;

while(first!=NULL || second!=NULL || carry!=0){

int val1=0;
if(first!=NULL)
val1=first->data;

int val2=0;
if(second!=NULL)
val2=second->data;

int sum=carry+val1+val2;

int digit=sum%10;

carry=sum/10;
if(first!=NULL)
first=first->next;

if(second!=NULL)
second=second->next;

}
return anshead;
}
*/