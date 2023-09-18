/*
Given an array of distinct integers. The task is to count all the \
triplets such that sum of two elements equals the third element.
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
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    int count=0;
	    for(int i=n-1;i>=2;i--){
	        int l,r;
	        l=0;r=i-1;
	        while(l<r){
	            if(arr[l]+arr[r]==arr[i]){
	                //cout<<arr[l]<<" "<<arr[r]<<" "<<arr[i]<<endl;
	                count++;
	                l++;
	                r--;
	            }else if(arr[l]+arr[r]<arr[i]){
	                l++;
	            }else if(arr[l]+arr[r]>arr[i]){
	                r--;
	            }
	        }
	    }
	    if(count){
	        cout<<count<<endl;
	    }else{
	        cout<<-1<<endl;
	    }
	}
	return 0;
}