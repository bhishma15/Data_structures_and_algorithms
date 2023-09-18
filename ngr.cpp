/*
Given an array, print the Next Greater Element (NGE) for every \
element. The Next greater Element for an element x is the first \
greater element on the right side of x in array. Elements for \
which no greater element exist, consider next greater element as -1.
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> solve(vector<ll> v){
	ll n=v.size();
	vector<ll> res;
	stack<ll> s;
	for(ll i=n-1;i>=0;i--){
		if(s.empty()){
			res.push_back(-1);
		}else if(s.top()>v[i]){
			res.push_back(s.top());
		}else if(s.top()<=v[i]){
			while(s.size()>0&&s.top()<=v[i]){
				s.pop();
			}
			if(s.size()==0){
				res.push_back(-1);
			}else{
				res.push_back(s.top());
			}
		}
		s.push(v[i]);
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}
		vector<ll> res=solve(v);
		for(ll i=0;i<n;i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}