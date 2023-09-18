/*
You are given a number N. You have to find the number \
 operations required to reach N from 0. You have 2 operations \
 available:

Double the number
Add one to the number
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10000];

//top down
int solve(int n){
    if(n==0||n==1){
        return n;
    }
    if(dp[n]!=-1)
    return dp[n];
    if(n%2==0){
        return dp[n]=min(solve(n-1),solve(n/2))+1;
    }else{
        return dp[n]=solve(n-1)+1;
    }
}

//bottem up
int solve2(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=min(dp[i-1],dp[i/2])+1;
        }
    }
    return dp[n];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    memset(dp,-1,sizeof(dp));
	    int n;
	    cin>>n;
	    int res=solve2(n);
	    cout<<res<<endl;
	}
	return 0;
}