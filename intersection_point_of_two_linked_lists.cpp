// Q.Write a C++ program to find the intersection point of two linked lists
// --->solution

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




int flength(node*head){
int l=0;
while(head!=NULL){
    l++;
    head=head->next;
}
return l;
}



node*position(node*head,int k){
    while(k--){
        head=head->next;
    }
    return head;
}



node* intersection(node*head1,node*head2){
   int l1=flength(head1);
   int l2=flength(head2);

   node*ptr1;
   node*ptr2;
   if(l1>l2){
     int k=l1-l2;
     ptr1=position(head1,k);
     ptr2=head2;
   }else{
       int k=l2-l1;
     ptr2=position(head2,k);
     ptr1=head1;
   }
    while(ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}




int main(){

linkedlist l;
int n1,n2;
cout<<"enter the size of 1 linked list : ";
cin>>n1;
cout<<"enter first linked list : ";
for(int i=0;i<n1;i++){
    int data;
    cin>>data;
  l.insertion(data);
}
l.display();

cout<<"enter the size of 2 linked list : ";
cin>>n2;
cout<<"enter second linked list : ";
linkedlist ll;
for(int i=0;i<n2;i++){
    int data;
    cin>>data;
  ll.insertion(data);
}
ll.display();


ll.head->next->next=l.head->next->next->next;

node*inter=intersection(l.head,ll.head);
if(inter){
cout<<inter->val;
}else{
    cout<<"NULL";
}

    return 0;
}
