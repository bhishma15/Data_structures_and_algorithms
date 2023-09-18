/*
Given an array arr of N integers. Find the contiguous \
sub-array with maximum sum.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int sum=0;
	    int mx=INT_MIN;
	    for(int i=0;i<n;i++){
	        if(sum+arr[i]<=arr[i]){
	            sum=arr[i];
	        }
	        else{
	            sum+=arr[i];
	        }   
	        mx=max(mx,sum);
	    }
	    cout<<mx<<endl;
	}
	return 0;
}