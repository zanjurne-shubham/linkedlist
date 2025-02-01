//Write a C++ program to merge multiple sorted linked lists into a single sorted linked list.
//-->solution
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


void mergethelinkedlist(vector<node*> &linkvector){
    while(linkvector.size()>1){
    node * newhead=nodemergemultilinkedlist(linkvector[0],linkvector[1]);
    linkvector.push_back(newhead);
    linkvector.erase(linkvector.begin());
    linkvector.erase(linkvector.begin());
    }
}

int main(){

linkedlist l;
int n;
cout<<"enter the size of 1 linked list : ";
cin>>n;
cout<<"enter the 1 sorted linked list the size of linked list is "<<n<<" : ";
for(int i=0;i<n;i++){
    int data;
    cin>>data;
    l.insertion(data);
}
l.display();

linkedlist ll;
int m;
cout<<"enter the size of 2 linked list : ";
cin>>m;
cout<<"enter the 2 sorted  linked list the size of linked list is "<<m<<" : ";
for(int i=0;i<m;i++){
    int data;
    cin>>data;
    ll.insertion(data);
}
ll.display();



linkedlist lll;
int o;
cout<<"enter the size of 3 linked list : ";
cin>>o;
cout<<"enter the 3 sorted linked list the size of linked list is "<<o<<" : ";
for(int i=0;i<o;i++){
    int data;
    cin>>data;
    lll.insertion(data);
}
lll.display();

vector<node*>linkvector;
linkvector.push_back(l.head);
linkvector.push_back(ll.head);
linkvector.push_back(lll.head);

mergethelinkedlist(linkvector);
linkedlist print;
print.head=linkvector[0];
print.display();
    return 0;
}