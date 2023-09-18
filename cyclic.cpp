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

//check for cycle
bool present(vector<node*> v,node *temp){
	for(int i=0;i<v.size();i++){
		if(v[i]==temp)
			return true;
	}
	return false;
}

//using hash table
bool isCyclic(node *head){
	vector<node *> hash;
	if(head==0)
		return false;
	while(head!=0){
		if(present(hash,head)){
		return true;
		}
		hash.push_back(head);
		head=head->next;
	}

	return false;
}

//two pointer method
bool cyclic(node *head){
	node *slow,*fast;
	slow=head;
	fast=head;
	while(slow&&fast&&fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			return true;
	}
	return false;
}

//find the starting point of cycle
node *find_start(node *head){
	node *slow,*fast;
	bool flg=false;
	slow=head;
	fast=head;
	while(slow&&fast&&fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			{
				flg=true;
				break;
			}
	}
	if(flg==false){
		return 0;
	}
	else{
		slow=head;
		while(slow!=fast){
			slow=slow->next;
			fast=fast->next;
		}
		return slow;
	}
}

void remove_cycle(node *head){
	node *slow,*fast,*prev;
	bool flg=false;
	slow=head;
	fast=head;
	while(slow&&fast&&fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			{
				flg=true;
				break;
			}
	}
	if(flg==false){
		return ;
	}
	else{
		slow=head;
		while(slow!=fast){
			prev=fast;
			slow=slow->next;
			fast=fast->next;
		}
		prev->next=0;
	}
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
	if(cyclic(head)){
		cout<<"cycle is present"<<endl;
	}
	else{
		cout<<"cycle is not present"<<endl;
	}
	remove_cycle(head);
	if(cyclic(head)){
		cout<<"cycle is present"<<endl;
	}
	else{
		cout<<"cycle is not present"<<endl;
	}
	return 0;
}