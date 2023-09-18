#include<bits/stdc++.h>
using namespace std;

bool solve(stack<int> s){
	queue<int> q;
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}

	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}

	while(!s.empty()){
		int n=s.top();
		s.pop();
		q.push(n);
		if(!s.empty()){
			int m=s.top();
			s.pop();
			q.push(m);
			if(abs(n-m)!=1){
				return false;
			}
		}
	}
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	return true;
}
int main(){
	//write your code here
	stack<int> s;
	s.push(2);
	s.push(3);
	s.push(8);
	s.push(5);
	s.push(5);
	if(solve(s)){
		cout<<"pairwise consecutive"<<endl;
	}else{
		cout<<"not consecutive"<<endl;
	}
}