#include<bits/stdc++.h>
using namespace std;

struct stk{
	queue<int> q1;
	queue<int> q2;
};

void psh(stk *s,int data){
 if(s->q1.empty()){
 	s->q2.push(data);
 }
 else{
 	s->q1.push(data);
 }
}

int pp(stk *s){
	if(s->q1.empty()&&s->q2.empty()){
		cout<<"Empty stack"<<endl;
		return -1;
	}
	if(!s->q1.empty()){
			int temp;
			int l=s->q1.size();
		for(int i=0;i<l-1;i++){
			temp=(s->q1).front();
			s->q1.pop();
			s->q2.push(temp);
		}
		temp=(s->q1).front();
		s->q1.pop();
		return temp;
	
	}else{
		int temp;
		int l=s->q2.size();
		for(int i=0;i<l-1;i++){
			temp=(s->q2).front();
			s->q2.pop();
			s->q1.push(temp);
		}
		temp=(s->q2).front();
		s->q2.pop();
		return temp;
	}
}
int main(){
	//write your code here
	stk *s=new stk;
	psh(s,4);
	psh(s,6);
	psh(s,4);
	psh(s,6);
	cout<<pp(s)<<endl;
	cout<<pp(s)<<endl;
}