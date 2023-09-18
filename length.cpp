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

int even_odd(node *head){
	node *temp=head;
	while(temp&&temp->next!=0){
		temp=temp->next->next;
	}

	if(!temp){
		return 0;
	}
	else{
		return 1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	int len=even_odd(head);
	if(len){
		cout<<"odd length"<<endl;
	}
	else{
		cout<<"even length"<<endl;
	}
	return 0;
}