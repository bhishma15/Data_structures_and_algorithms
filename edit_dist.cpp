/*
Given two strings s and t. Find the minimum number of operations 
that need to be performed on str1 to convert it to str2. 
The possible operations are:

Insert
Remove
Replace
*/

#include<bits/stdc++.h>

using namespace std;
 

int solve(int **dp,string a,string b,int n,int m){
        	if(n==0)
        		return m;
        	if(m==0)
        		return n;
        		if(dp[n][m]!=-1)
        		return dp[n][m];
        	if(a[n-1]==b[m-1]){
        		return dp[n][m]=solve(dp,a,b,n-1,m-1);
        	}
        	return dp[n][m]=1+min(min(solve(dp,a,b,n,m-1),solve(dp,a,b,n-1,m)),solve(dp,a,b,n-1,m-1));
        }
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  string a,b;
  cin>>a>>b;
  int n=a.length();
		    int m=b.length();
		    int **dp=new int*[n+1];
		    for(int i=0;i<=n;i++){
		        dp[i]=new int[m+1];
		    }
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=m;j++){
		            dp[i][j]=-1;
		        }
		    }
		    cout<<solve(dp,a,b,n,m);
  return 0;
}