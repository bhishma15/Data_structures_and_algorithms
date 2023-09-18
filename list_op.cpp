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

void traverse(node *head){
	if(head==0)
		return;
	cout<<head->data<<" ";
	traverse(head->next);
	return;
}

void rev_traverse(node *head){
	if(head==0)
		return;
	rev_traverse(head->next);
	cout<<head->data<<" ";
	return;
}

void insert(node **head,int data,int pos){
	node *t=new node(data);
	if(pos==1){
		t->next=*head;
		*head=t;
	}
	else{
		node *temp=*head;
		for(int i=1;i<pos-1;i++){
			temp=temp->next;
			if(temp==0)
				break;
		}
		if(temp==0)
		{
			cout<<"Not possible"<<endl;
		}
		t->next=temp->next;
		temp->next=t;
	}
	return;
}

void delete_node(node **head,int pos){
	if(*head==0)
		return;
	if(pos==1){
		node *t=*head;
		*head = (*head)->next;
		delete(t);
		return;
	}
	else{
		node *temp,*t;
		temp=*head;
		for(int i=1;i<pos-1;i++){
			temp=temp->next;
			if(temp==0)
				break;
		}
		if(temp==0)
		{
			cout<<"Not possible"<<endl;
			return;
		}
		t=temp->next;
		temp->next=t->next;
		delete(t);
		return;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	//traverse(head);
	//cout<<endl;
	traverse(head);
	cout<<endl;
	delete_node(&head,5);
	traverse(head);
	cout<<endl;
	return 0;
}