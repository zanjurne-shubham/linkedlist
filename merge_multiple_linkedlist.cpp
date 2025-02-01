
// Q.Write a C++ program that merges multiple sorted linked lists into a single sorted linked list.
//---->solution

#include<iostream>
using namespace std;

//class for creating a node
class node{
    public:
    int val;
    node*next;
    node(int data){
        val=data;
        next=NULL;
    }
};

//class for creating a linkedlist
class linkedlist{
  public:
  node*head;
  linkedlist(){
    head=NULL;
  }


//function for insert a node in linkedlist
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

 //for display a linkedlist
  void display(){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
  
  }

};

//forction to merge a two linkedlist 
node*nodemergemultilinkedlist(node*head1,node*head2){
node*ptr1=head1;
node*ptr2=head2;
node*back=NULL;
node*cpyhead=NULL;
if(ptr1->val<ptr2->val){
 cpyhead=ptr1;
 back=ptr1;
 ptr1=ptr1->next;
}else{
 cpyhead=ptr2;
 back=ptr2;
 ptr2=ptr2->next;
}
 while(ptr1!=NULL and ptr2!=NULL){
    if(ptr1->val<ptr2->val){
        back->next=ptr1;
        back=ptr1;
        ptr1=ptr1->next;
    }else{
       back->next=ptr2;
       back=ptr2;
        ptr2=ptr2->next;
    }
}
if(ptr1==NULL){
    back->next=ptr2;
}else{
    back->next=ptr1;
}
return cpyhead;
}


int main(){

//linkedlist no-1 

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


//linkedlist no-2 

linkedlist ll;
int m;
cout<<"enter the size of 1 linked list : ";
cin>>m;
cout<<"enter the 1 linked list the size of linked list is "<<m<<" : ";
for(int i=0;i<m;i++){
    int data;
    cin>>data;
    ll.insertion(data);
}
ll.display();


//linkedlist no-3 
linkedlist lll;
int o;
cout<<"enter the size of 1 linked list : ";
cin>>o;
cout<<"enter the 1 linked list the size of linked list is "<<o<<" : ";
for(int i=0;i<o;i++){
    int data;
    cin>>data;
    lll.insertion(data);
}
lll.display();


//merge 2 linked list 
 cout<<endl;
 cout<<"solution"<<endl;
 cout<<"two merge linked list is = ";
node*newhead=nodemergemultilinkedlist(l.head,ll.head);
linkedlist print;
print.head=newhead;
print.display();


//merge 3linked list 
 cout<<"three merge linked list is = ";
newhead=nodemergemultilinkedlist(print.head,lll.head);
print.head=newhead;
print.display();


    return 0;
}
