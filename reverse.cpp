#include<bits/stdc++.h>
using namespace std;

queue<int> reverse(queue<int> q){
	stack<int> s;
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	return q;
}
int main(){
	queue<int> q;
	q.push(3);
	q.push(4);
	q.push(6);
	cout<<q.front()<<endl;
	q=reverse(q);
	cout<<q.front()<<endl;
	
}