//Q.Write a C++ program to delete the kth node from the end of a linked list.
 //--->solution

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node*next;
    node(int data){
        val=data;
        next=NULL;
    }
};

class linkedlist{
    public:
    node*head;
    linkedlist(){
        head=NULL;
    }

    void insertion(int data){
        if(head==NULL){
            node*newnode=new node(data);
            head=newnode;
            return;
        }
        node*temp=head;
        node*newnode=new node(data);
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }


void display(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
};



void deletethenodefromend(node* &head,int k ){
node* ptr1=head;
node* ptr2=head;
int v=k;
while(v--){
ptr1=ptr1->next;
}

if(ptr1==NULL){
node*temp=head;
head=head->next;
free(temp);
return;
}

while(ptr1->next!=NULL){
   ptr1=ptr1->next; 
   ptr2=ptr2->next;
}
node*temp=ptr2->next;
ptr2->next=ptr2->next->next;
free(temp);
}



int main(){
    int n;
    cout<<"enter the number of elements in linked list : ";
    cin>>n;
cout<<"enter first linked list : ";
linkedlist l;
for(int i=0;i<n;i++){
    int data;
    cin>>data;
  l.insertion(data);
}
int k;
cout<<"enter the value of k : ";
cin>>k;
l.display();
deletethenodefromend(l.head,k);
l.display();
    return 0;
}