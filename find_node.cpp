

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

//find nth node from end of list takes o(n2)
node *find(node *head,int n){
	if(head==0)
		return 0;
	node *temp=head;
	node *t=temp->next;
	int count=0;
	while(t){
		count++;
		t=t->next;
	}
	if(count==n-1){
		return temp;
	}
	else if(count<n-1){
		cout<<"lesser nodes present"<<endl;
		return 0;
	}
	else{
		return find(head->next,n);
	}
	
}

//it takes o(n) time with hashing
node *find_node(node *head,int n){
	vector<node*> hash;
	int pos=1;
	while(head!=0){
		hash.push_back(head);
		head=head->next;
	}
	int m=hash.size();
	if(n<=m){
		return hash[m-n];
	}
	else{
		cout<<"lesser nodes in list"<<endl;
		return 0;
	}
}

//only i=one scan required
node *find_nthnode(node *head,int n){
	if(head==0)
	{
		return 0;
	}
	node *temp=head;
	for(int i=1;i<n;i++){
		temp=temp->next;
		if(temp==0)
			break;
	}
	if(temp==0)
		return 0;
	if(temp->next==0)
		return head;
	node *pnode=head;
	while(temp->next!=0){
		temp=temp->next;
		pnode=pnode->next;
	}
	return pnode;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	node *t=find_nthnode(head,1);
	if(t==0){
		cout<<"not possible "<<endl;
	}
	else{
		cout<<t->data<<endl;
	}
	
	return 0;
}