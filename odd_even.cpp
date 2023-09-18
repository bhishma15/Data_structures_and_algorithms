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
	return;
}

//arrange even node at start of list
node* arrange(node *head){
	if(head==0)
		return head;
	queue<node*> q;
	node *head1=0,*temp,*prev;
	while(head){
		if(head->data%2==0){
			if(head1==0){
				head1=head;
				prev=head1;
			}
			else{
				prev->next=head;
				prev=prev->next;
			}
		}
		else{
			q.push(head);
		}
		head=head->next;
	}
	while(!q.empty()){
		prev->next=q.front();
		q.pop();
		prev=prev->next;
	}
	return head1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	node *t=arrange(head);
	traverse(t);
	return 0;
}