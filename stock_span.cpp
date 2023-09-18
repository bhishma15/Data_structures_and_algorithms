/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> solve(vector<ll> v){
	ll n=v.size();
	vector<ll> res;
	stack<pair<ll,ll> > s;
	for(ll i=0;i<n;i++){
		if(s.empty()){
			res.push_back(-1);
		}else if(s.top().first>v[i]){
			res.push_back(s.top().second);
		}else if(s.top().first<=v[i]){
			while(s.size()>0&&s.top().first<=v[i]){
				s.pop();
			}
			if(s.size()==0){
				res.push_back(-1);
			}else{
				res.push_back(s.top().second);
			}
		}
		s.push({v[i],i});
	}
	for(int i=0;i<res.size();i++){
		res[i]=i-res[i];
	}
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