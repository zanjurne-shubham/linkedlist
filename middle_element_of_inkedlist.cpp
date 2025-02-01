//Q.Write a C++ program to find the middle element of a linked list.
//--->solution

#include<iostream>
#include<vector>
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
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
  
  }

};

node*findmid(node*head){
node*ptr1=head;
node*ptr2=head;
if(ptr2==NULL){
    return ptr2;
} 

while(ptr2->next!=NULL and ptr2!=NULL and ptr2->next->next!=NULL){
ptr2=ptr2->next->next;
ptr1=ptr1->next;
}
return ptr1;
}

int main(){ 
linkedlist l;
int n;
cout<<"enter the size of 1 linked list : ";
cin>>n;
cout<<"enter the 1 linked list the size of linked list is "<<n<<" : ";
for(int i=0;i<n;i++){
    int data;
    cin>>data;
    l.insertion(data);
}
l.display();

node*mid=findmid(l.head);
cout<<mid->val<<endl;

    return 0;
}