
/*
You are given weights and values of N items, put these items in a \
knapsack of capacity W to get the maximum total value in the knapsack.\
 Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] \
which represent values and weights associated with N items \
respectively. Also given an integer W which represents knapsack \
capacity, find out the maximum value subset of val[] such that \
sum of the weights of this subset is smaller than or equal to W.\
 You cannot break an item, either pick the complete item, or don’t 
pick it (0-1 property).

*/


#include<bits/stdc++.h>
using namespace std;
int solve(int **dp,int val[],int wt[],int n,int w){
    if(n==0||w==0)
    return 0;
    if(dp[n][w]!=-1)
    return dp[n][w];
    if(wt[n-1]>w){
        return dp[n][w]=solve(dp,val,wt,n-1,w);
    }else{
        return dp[n][w]=max(solve(dp,val,wt,n-1,w),val[n-1]+solve(dp,val,wt,n-1,w-wt[n-1]));
    }
}
int main()
 {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n,w;
	    cin>>n>>w;
	    int val[n],wt[n];
	    for(int i=0;i<n;i++){
	        cin>>val[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>wt[i];
	    }
	    int **dp=new int*[n+1];
	    for(int i=0;i<=n;i++){
	        dp[i]=new int[w+1];
	    }
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=w;j++){
	            dp[i][j]=-1;
	        }
	    }
	    int ans=solve(dp,val,wt,n,w);
	    cout<<ans<<endl;
	}
	return 0;
}