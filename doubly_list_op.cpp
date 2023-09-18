#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node *next;
	node *prev;
	node(int data){
		this->data=data;
		this->next=0;
		this->prev=0;
	}
};

void insert(node **head,int data,int pos){
	node *n=new node(data);
	if(pos==1){
		n->next=*head;
		if(*head){
			(*head)->prev=n;
		}
		*head=n;
		return;
	}
	else{
		node *temp=*head;
		for(int i=1;i<pos-1;i++){
			temp=temp->next;
			if(temp==0)
				return;
		}
		n->next=temp->next;
		n->prev=temp;
		if(temp->next)
		{
			temp->next->prev=n;
		}
		temp->next=n;
		return;
	}
}
node* create_list(vector<int> v){
	node *head=0;
	if(v.size()==0)
		return head;
	for(int i=0;i<v.size();i++){
		insert(&head,v[i],i+1);
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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	traverse(head);

	return 0;
}