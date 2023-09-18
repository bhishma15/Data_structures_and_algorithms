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
	if(head1==0)
		return;
	cout<<head1->data<<" ";
	traverse(head1->next);
	return ;
}

//reverse linked list in pairwise recursive code
node* reverse(node *head){
	if(head==0||head->next==0)
		return head;
	else{
		node *temp;
		temp=head->next;
		head->next=temp->next;
		temp->next=head;
		head=temp;
		head->next->next=reverse(head->next->next);
		return head;
	}
}

//reverse linked list in pairwise iterative code
node *reverse_pair(node *head){
	if(!head)
		return 0;
	node *curr=head;
	node *temp=0,*head1=0;
	while(curr!=0&&curr->next!=0){
		if(temp!=0)
			temp->next->next=curr->next;
		temp=curr->next;
		curr->next=temp->next;
		temp->next=curr;
		if(head1==0)
			head1=temp;
		curr=curr->next;
	}
	return head1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	traverse(head);
	cout<<endl;
	node *t=reverse_pair(head);
	traverse(t);
	cout<<endl;
	return 0;
}