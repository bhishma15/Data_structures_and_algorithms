#include<bits/stdc++.h>

using namespace std;

//program to implement que using stack
struct que{
	stack<int> s1;
	stack<int> s2;
};

void enQ(que *q,int data){
	q->s1.push(data);
}

int deQ(que *q){
	if(!q->s2.empty()){
		int temp=q->s2.top();
		q->s2.pop();
		return temp;
	}
	else{
		if(q->s1.empty())
		{
			cout<<"Stack underflow error"<<endl;
			return -1;
		}
		while(!q->s1.empty()){
			q->s2.push(q->s1.top());
			q->s1.pop();
		}
		int temp=q->s2.top();
		q->s2.pop();
		return temp;
	}
}
int main(){
	que *q=new que;
	enQ(q,3);
	enQ(q,5);
	enQ(q,2);
	enQ(q,1);
	cout<<deQ(q)<<endl;
	cout<<deQ(q)<<endl;
	cout<<deQ(q)<<endl;
	cout<<deQ(q)<<endl;
	cout<<deQ(q)<<endl;
}