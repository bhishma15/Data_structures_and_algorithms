/*
Given a sequence A of size N, find the length of the longest \
increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence \
of a given sequence in which the subsequence's elements are in \
sorted order, lowest to highest, and in which the subsequence \
is as long as possible. This subsequence is not necessarily \
contiguous, or unique.
*/

#include<iostream>
using namespace std;
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
	    if(n==1){
	        cout<<1<<endl;
	    }else{
	        int dp[n];
	        for(int i=0;i<n;i++){
	            dp[i]=1;
	        }
	        int mx=1;
	        for(int i=1;i<n;i++){
	            for(int j=i-1;j>=0;j--){
	                if(arr[i]>arr[j]&&dp[i]<=dp[j]){
	                    dp[i]=dp[j]+1;
	                    mx=max(dp[i],mx);
	                }
	            }
	        }
	        cout<<mx<<endl;
	    }
	}
	return 0;
}