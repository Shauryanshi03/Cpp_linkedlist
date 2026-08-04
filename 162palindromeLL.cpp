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

class solution{
    private:
    bool checkpalindrome(vector<int> arr){
       
        int n=arr.size();
        int s=0;
        int e=n-1;

        while(s<=e){
            if(arr[s]!=arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }

public:
bool ispalindrome(Node* head){
    vector<int> arr;

    Node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkpalindrome(arr);
}
};

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(2);
    head->next->next->next=new Node(1);

    solution obj;

    cout<<obj.ispalindrome(head);

    return 0;
}

/*APPROACH 2
Node* getmid(Node* head){
Nde* slow=head;
Node* fast=head->next;

while(fast!=NULL && fast->next!=NULL){
fast=fast->next->next;
slow=slow->next;
}
return slow;
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

bool ispalindrome(Node* head){
if(head->next==NULL){
return true;
}

Node* middle=getmid(head);

Node* temp=middle->next;
middle->next=reverse(temp);

Node* head1=head;
Node* head2=middle->next;

while(head2!=NULL){
if(head1->data!=head2->data){
return false;
}
head1=head1->next;
head2=head2->next;
}

temp=middle->next;
middle->next=reverse(temp);

return true;
}
*/