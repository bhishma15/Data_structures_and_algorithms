#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node *next;
	node(int data){
		this->data=data;
		this->next=0;
	}
};

node* create_list(vector<int> v){
	node *head=0;
	if(v.size()==0)
		return head;
	node *t=new node(v[0]);
	head=t;
	for(int i=1;i<v.size();i++){
		node *temp=new node(v[i]);
		t->next=temp;
		t=t->next;
	}
	return head;
}

//insert node in sorted list
void insert(node *head,node *n){
	if(head==0||n==0)
		return;
	node *temp,*curr;
	curr=head;
	temp=curr;
	while(curr!=0&&curr->data< n->data){
		temp=curr;
		curr=curr->next;
	}
	if(temp){
		n->next=temp->next;
		temp->next=n;
	}
}

void traverse(node *head){
	if(head==0)
		return ;
	cout<<head->data<<" ";
	traverse(head->next);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={1,2,3,6};
	node *head=create_list(v);
	//write your code here
	traverse(head);
	node *n=new node(5);
	insert(head,n);
	cout<<endl;
	traverse(head);
	return 0;
}