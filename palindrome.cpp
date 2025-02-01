//Q.Write a C++ program to check whether a linked list is a palindrome.
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
 void findpalindronlinkedlist(node* &head,node* &originalhead,bool &tf){
 if(head==NULL){
    return ;
 }
findpalindronlinkedlist(head->next,originalhead,tf);
 if(head->val==originalhead->val){
   originalhead=originalhead->next;
 }else{
  tf=false;
 }
}

int main(){ 
linkedlist l;
int n;
cout<<"enter the size of  linked list : ";
cin>>n;
cout<<"enter the linked list and the size of linked list is "<<n<<" : ";
for(int i=0;i<n;i++){
    int data;
    cin>>data;
    l.insertion(data);
}
node*duplicate=l.head;
bool tf=true;
findpalindronlinkedlist(duplicate,duplicate,tf);
if(tf){
  cout<<" linked list is  palindrome";
}else{
  cout<<" linked list is not  palindrome";
}
    return 0;
}
