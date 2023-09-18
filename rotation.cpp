/*
find the count of rotations in rotated sorted array
*/


#include<bits/stdc++.h>

using namespace std;
 

int search(vector<int> arr){
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
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  vector<int> v={1,1,1,1,1};
  int res=search(v);
  cout<<res<<endl;
  return 0;
}