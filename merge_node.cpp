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
		return ;
	cout<<head->data<<" ";
	traverse(head->next);
}

bool present(vector<node*> v, node *temp){
	for(int i=0;i<v.size();i++){
		if(v[i]==temp)
			return true;
	}
	return false;
}

//using hash table
node* merge_node(node *head1,node *head2){
	vector<node*> v;
	while(head1!=0){
		v.push_back(head1);
		head1=head1->next;
	}
	while(head2!=0){
		if(present(v,head2)){
			return head2;
		}
		head2=head2->next;
	}
	return 0;
}

//using stack
node* merge_point(node *head1,node* head2){
	stack <node*> s1,s2;
	while(head1!=0){
		s1.push(head1);
		head1=head1->next;
	}
	while(head2!=0){
		s2.push(head2);
		head2=head2->next;
	}
	node *temp=0,*a=0,*b=0;
	while(!s1.empty()||!s2.empty()){
		a=s1.top();
		b=s2.top();
		if(a==b)
		{
			temp=a;
			s1.pop();
			s2.pop();
		}
		else{
			return temp;
		}
		
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head1=create_list(v);
	node *head2=0;
	node *temp=new node(10);
	temp->next=head1->next;
	head2=temp;
	//write your code here
	node *t=merge_point(head1,head2);
	cout<<t->data<<endl;
	return 0;
}