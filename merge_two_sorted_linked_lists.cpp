//Q.Write a C++ program to merge two sorted linked lists into a single sorted linked list
//-->solution
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


node* mergethelinkedlist(node*head1,node*head2){
 if(head1==NULL and head2==NULL){
    return NULL;
 }else if(head1==NULL){
    return head2;
 }else if(head2==NULL){
    return head1;
 }

node*ptr1=head1;
node*ptr2=head2;
node*ptr3=NULL;
node*temphead=NULL;

if((ptr1->val)<(ptr2->val)){
    ptr3=ptr1;
    temphead=ptr1;
    ptr1=ptr1->next;
}else{
    ptr3=ptr2; 
    temphead=ptr2;
      ptr2=ptr2->next;
}

while(ptr1!=NULL and ptr2!=NULL){
   if(ptr1->val<ptr2->val){
         ptr3->next=ptr1;
         ptr1=ptr1->next;
   }
   else{
      ptr3->next=ptr2;
      ptr2=ptr2->next;

   }
   ptr3=ptr3->next;
}

if(ptr1==NULL){
    ptr3->next=ptr2;
}if(ptr2==NULL){
      ptr3->next=ptr1;
}
return temphead;

}


int main(){
    int n1,n2;
    cout<<"enter the size of first linked list :";
    cin>>n1;
cout<<"enter first sorted linked list : ";
linkedlist l;
for(int i=0;i<n1;i++){
    int data;
    cin>>data;
  l.insertion(data);
}
l.display();

 cout<<"enter the size of second linked list :";
    cin>>n2;
cout<<"enter second sorted linked list : ";
linkedlist ll;
for(int i=0;i<n2;i++){
    int data;
    cin>>data;
  ll.insertion(data);
}
ll.display();


node *cpyhead=mergethelinkedlist(l.head,ll.head);
linkedlist lll;
lll.head=cpyhead;
lll.display();  

    return 0;
}