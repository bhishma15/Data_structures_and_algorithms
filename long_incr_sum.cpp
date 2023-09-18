

/*
Given an array arr of N positive integers, the task is to find the \
maximum sum increasing subsequence of the given array.
*/

#include<iostream>
using namespace std;

int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    if(n==1){
	        return arr[0];
	    }else{
	        int dp[n];
	        for(int i=0;i<n;i++){
	            dp[i]=arr[i];
	        }
	        int mx=arr[0];
	        for(int i=1;i<n;i++){
	            for(int j=i-1;j>=0;j--){
	                if(arr[i]>arr[j]&&dp[i]<=dp[j]+arr[i]){
	                    dp[i]=dp[j]+arr[i];
	                    mx=max(dp[i],mx);
	                }
	            }
	        }
	        return mx;
	    }
	}  

int main()
 {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    int ans=solve(arr,n);
	    cout<<ans<<endl;
	}
	return 0;
}

