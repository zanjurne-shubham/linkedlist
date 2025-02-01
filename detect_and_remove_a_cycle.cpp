// Q.Write a C++ program to detect and remove a cycle in a linked list.
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

bool findcycle(node*head){
node*ptr1=head;
node*ptr2=head;
if(ptr2==NULL){
    return false;
}
while(ptr2!=NULL and ptr2->next!=NULL){
     ptr1=ptr1->next;
    ptr2=ptr2->next->next;
    if(ptr1==ptr2){
        return true;
    }
   
}
return false;
}

void removecycle(node*head){
node*slow=head;
node*fast=head;

do{
     slow=slow->next;
     fast=fast->next->next;   
}while(slow!=fast);

while(head->next!=slow->next){
    head=head->next;
    slow=slow->next;
}
slow->next=NULL;
}

int main(){ 
linkedlist l;
int n;
cout<<"enter the size of 1 linked list : ";
cin>>n;
cout<<"enter the 1 linked list &  the size of linked list is "<<n<<" : ";
for(int i=0;i<n;i++){
    int data;
    cin>>data;
    l.insertion(data);
}

if (n >= 4) {
    l.head->next->next->next->next->next9= l.head->next->next;  // Creates a cycle for testing
}
bool tf=findcycle(l.head);

if(tf){
    cout<<"cycle is present in linked list"<<endl;
    removecycle(l.head);
    l.display();
}
    return 0;
}