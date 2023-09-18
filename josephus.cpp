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

int find(int n,int m){
	node *p,*q;
	p=new node(1);
	q=p;
	for(int i=2;i<=n;i++){
		p->next=new node(i);
		p=p->next;
		p->data=i;
	}
	p->next=q;
	for(int count=n;count>1;count--){
		int j=0;
		while(j<m-1){
			p=p->next;
			j++;
		}
		node *t=p->next;
		p->next=p->next->next;
		delete(t);
	}
	return p->data;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3};
	node *head=create_list(v);
	//write your code here
	int n,m;
	cin>>n>>m;
	int ans=find(n,m);
	cout<<ans<<endl;
	return 0;
}