/*

Given an array arr[] of size N, check if it can be partitioned into
 two parts such that the sum of elements in both parts is the same.


*/

#include<bits/stdc++.h>

using namespace std;
 

int solve(vector<vector<int> >& dp,int arr[],int n,int w){
        if(w==0)
        return 1;
        if(n==0)
        return 0;
        if(dp[n][w]!=-1)
        return dp[n][w];
        if(arr[n-1]>w){
            return dp[n][w]=solve(dp,arr,n-1,w);
        }else{
            return dp[n][w]=solve(dp,arr,n-1,w)||solve(dp,arr,n-1,w-arr[n-1]);
        }
    }

 int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)
        return 0;
        sum=sum/2;
        vector<int> v(sum+1,-1);
        vector<vector<int> > dp(N+1,v);
        return solve(dp,arr,N,sum);
    }
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}