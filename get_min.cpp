#include<bits/stdc++.h>
using namespace std;


void push(stack<int> *a,stack<int> *b,int data){
	a->push(data);
	if(b->empty()){
		b->push(data);
	}
	else if(a->top()<=b->top()){
		b->push(a->top());
	}
	else{
		b->push(b->top());
	}
}

void pop(stack<int> *a,stack<int> *b){
	if(!a->empty()){
		a->pop();
		b->pop();
	}
	else{
		cout<<"Empty stack"<<endl;
		return;
	}
}

//find the minimum in the stck
int get_min(stack<int> *b){
	if(b->empty()){
		cout<<"stack empty"<<endl;
		return -1;
	}
	else{
		return b->top();
	}
}
int main(){
	stack<int> a;
	stack<int> b;
	push(&a,&b,3);
	push(&a,&b,5);
	push(&a,&b,1);
	cout<<get_min(&b)<<endl;
	pop(&a,&b);
	cout<<get_min(&b)<<endl;
}