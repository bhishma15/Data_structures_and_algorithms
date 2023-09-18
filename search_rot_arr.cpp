/*
find the element in rotated sorted array
*/


#include<bits/stdc++.h>

using namespace std;
 

int search_ind(vector<int> arr){
	int n=arr.size();
	int start=0;
	int end=n-1;
	if(arr[start]<=arr[end])
		return 0;
	while(start<=end){
		int mid=start+(end-start)/2;
		int next=(mid+1)%n;
		int prev=(mid+n-1)%n;
		if(arr[prev]>arr[mid]&&arr[mid]<=arr[next]){
			return mid;
		}else if(arr[start]<=arr[mid]){
			start=mid+1;
		}else if(arr[mid]<=arr[end]){
			end=mid-1;
		}
	}
	return -1;
}

int search(vector<int> v,int start,int end,int x){
	while(start<=end){
		int mid=start+(end-start)/2;
		if(x==v[mid]){
			return mid;
		}else if(x<v[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return -1;
}

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  vector<int> v={3,4,5,6,1,2};
  int x=5;
  int ind=search_ind(v);
  int l=search(v,0,ind-1,x);
  int r=search(v,ind,v.size()-1,x);
  if(l!=-1){
  	cout<<l;
  }else{
  	cout<<r<<endl;
  }
  return 0;
}