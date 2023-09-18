/*
Given a value N, find the number of ways to make change for N cents,
if we have infinite supply of each of S = { S1, S2, .. , SM } valued 
coins. 


*/

#include<bits/stdc++.h>

using namespace std;
 

long long int count( int S[], int m, int n )
    {
       
       long long dp[n+1];
       memset(dp,0,sizeof(dp));
       dp[0]=1;
       for(int i=0;i<m;i++){
           for(int j=S[i];j<=n;j++){
               dp[j]+=dp[j-S[i]];
           }
       }
        return dp[n];
        
    }
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}