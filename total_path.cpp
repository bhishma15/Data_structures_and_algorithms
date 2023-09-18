/*
The problem is to count all the possible paths from top left to \
bottom right of a MxN matrix with the constraints that from each \
cell you can either move to right or down.
*/

#include<bits/stdc++.h>

using namespace std;
 

int solve(int m,int n){
	if(m==0||n==0)
		return 1;
	return solve(m-1,n)+solve(m,n-1);
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int t;
  cin>>t;
  while(t--){
  	int m,n;
  	cin>>m>>n;
  	cout<<solve(m-1,n-1)<<endl;
  }
  return 0;
}