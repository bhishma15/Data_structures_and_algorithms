#include<bits/stdc++.h>
using namespace std;

//given an array and have to find max consucutives elemenst preceding which less than or equal to a[i]
vector<int> find_span(vector<int> a){
	vector<int> s;
	for(int i=0;i<a.size();i++){
		int j=1;
		while(j<=i&&a[i]>a[i-j])
			j++;
		s.push_back(j);
	}
	return s;
}

//efficient sol using stack
vector<int> find(vector<int> a){
	stack<int> stk;
	vector<int> s;
	int p;
	for(int i=0;i<a.size();i++){
		while(!stk.empty()&&a[i]>a[stk.top()]){
			stk.pop();
		}
		if(stk.empty()){
			p=-1;
		}
		else{
			p=stk.top();
		}
		s.push_back(i-p);
		stk.push(i);
	}
	return s;
}

int main(){
	vector<int> a={6,3,4,5,2},s;
	s=find(a);
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
}