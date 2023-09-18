#include<bits/stdc++.h>
using namespace std;

void insert_at_bottem(stack<int> *s,int data)
{
	int temp;
	if(s->empty()){
		s->push(data);
		return;
	}
	temp=s->top();
	s->pop();
	insert_at_bottem(s,data);
	s->push(temp);
	return;
}

//reverse the stack
void reverse(stack<int> *s){
	int data;
	if(s->empty())
		return;
	data=s->top();
	s->pop();
	reverse(s);
	insert_at_bottem(s,data);
	return;
}

void print(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	print(s);
	reverse(&s);
	print(s);
}