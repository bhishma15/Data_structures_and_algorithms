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

void traverse(node *head1){
	node *temp=head1;
	if(temp==0)
		return ;
	cout<<temp->data<<" ";
	temp=temp->next;
	while(temp!=head1){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return;
}

void split(node *head,node** head1,node** head2){
	if(head==0)
		return ;
	node *slow,*fast;
	slow=fast=head;
	while(fast->next!=head&&fast->next->next!=head){
		slow=slow->next;
		fast=fast->next->next;
	}

	if(fast->next->next==head){
		fast=fast->next;
	}

	*head1=head;
	if(head->next!=head){
		*head2=slow->next;
	}
	fast->next=slow->next;
	slow->next=head;
	
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	node *temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->next=head;
	node *head1,*head2;
	head1=head2=0;
	split(head,&head1,&head2);
	traverse(head1);
	cout<<endl;
	traverse(head2);
	return 0;
}