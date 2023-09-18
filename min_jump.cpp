/*
Given an array of integers where each element represents the max \
number of steps that can be made forward from that element.
 The task is to find the minimum number of jumps to reach the 
 end of the array (starting from the first element). If an element 
 is 0, then cannot move through that element.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    int arr[n],dp[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        dp[i]=INT_MAX-1;
	    }
	    
	    if(arr[0]==0){
	        cout<<-1<<endl;
	    }else{
	        dp[0]=0;
	        for(int i=1;i<n;i++){
                for(int j=i-1;j>=0;j--){
                   if(j+arr[j]>=i){
                       dp[i]=min(dp[i],dp[j]+1);
                   }
                }
            }
            if(dp[n-1]==INT_MAX-1){
                cout<<-1<<endl;
            }else{
                cout<<dp[n-1]<<endl;
              // cout<<INT_MAX<<endl;
            }
	    }
	    
	}
	return 0;
}