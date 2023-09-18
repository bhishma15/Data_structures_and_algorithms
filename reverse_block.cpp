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

bool hasKnodes(node *head,int k){
	int i=0;
	while(head&&i<k){
		head=head->next;
		i++;
	}
	if(i==k)
		return true;
	return false;
}

node* getNxtofK(node *head,int k){
	if(!head)
		return head;
	int i=0;
		node *kth=head;
		while(i<k&&kth){
			i++;
			kth=kth->next;
		}
		if(i==k && kth!=0)
			return kth;
		return head->next;
}

node *reverseBlock(node *head,int k){
	if(k==0||k==1)
		return head;
	node *curr=head,*temp,*newHead,*nxt;
	if(hasKnodes(curr,k-1)){
		newHead=getNxtofK(curr,k-1);
	}
	else{
		newHead=head;
	}
	while(curr&&hasKnodes(curr,k)){
		temp=getNxtofK(curr,k);
		int i=0;
		while(i<k){
			nxt=curr->next;
			curr->next=temp;
			temp=curr;
			curr=nxt;
			i++;
		}
	}
	return newHead;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,5,3,8};
	node *head=create_list(v);
	//write your code here
	traverse(head);
	cout<<endl;
	node *t=reverseBlock(head,3);
	traverse(t);
	return 0;
}