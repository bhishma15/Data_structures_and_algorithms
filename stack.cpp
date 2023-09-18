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

void push(node **stk,int data){
	node *t=new node(data);
	if(t==0){
		cout<<"Stack overflow"<<endl;
		return;
	}
	t->next=*stk;
	*stk=t;
	return;
}

void pop(node **stk){
	node *t=*stk;
	if(t==0){
		cout<<"stack underflow"<<endl;
		return;
	}
	*stk=(*stk)->next;
	delete(t);
	return;
}

int top(node* stk){
	node *t=stk;
	if(t==0){
		cout<<"stack is empty"<<endl;
		return -1;
	}
	return t->data;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	node *stk=0;
	push(&stk,10);
	push(&stk,5);
	cout<<top(stk)<<endl;
	pop(&stk);
	cout<<top(stk)<<endl;
	return 0;
}