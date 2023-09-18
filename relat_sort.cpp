/*
Given two arrays A1[] and A2[] of size N and M respectively. \
The task is to sort A1 in such a way that the relative order \
among the elements will be same as those in A2. For the elements \
not present in A2, append them at last in sorted order. \
It is also given that the number of elements in A2[] are \
smaller than or equal to number of elements in A1[] and A2[] has\
 all distinct elements.
*/

#include<bits/stdc++.h>

using namespace std;
 

void solve(){
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<m;i++){
		int count=mp[b[i]];
		while(count--){
			cout<<b[i]<<" ";
		}
		mp.erase(b[i]);
	}
	for(auto x:mp){
		int count=x.second;
		while(count--){
			cout<<x.first<<" ";
		}
	}
	cout<<endl;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int t;
  cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}