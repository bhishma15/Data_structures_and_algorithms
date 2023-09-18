/* 
sort an array using heapsort method
*/

#include<bits/stdc++.h>

using namespace std;
 

void heapify(int arr[],int n,int i){
	if(i>=n)return;
	int l,r,mx=i;
	l=2*i+1;
	r=2*i+2;
	if(l<n&&arr[i]<arr[l]){
		mx=l;
	}
	if(r<n&&arr[mx]<arr[r]){
		mx=r;
	}
	if(mx!=i){
		swap(arr[mx],arr[i]);
		heapify(arr,n,mx);
	}
	return;
}

void buildheap(int arr[],int n){
	for(int i=(n/2)-1;i>=0;i--){
		heapify(arr,n,i);
	}
	return;
}

void heapsort(int arr[],int n){
	buildheap(arr,n);
	for(int i=n-1;i>=0;i--){
		swap(arr[i],arr[0]);
		heapify(arr,i,0);
	}
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int arr[]={6,1,3,2,4,5};
  int n=6;
  heapsort(arr,n);
  for(int i=0;i<n;i++){
  	cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}