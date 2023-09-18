#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int s,int e){
	int mid=(s+e)/2;
	int temp[100];
	int i,j,k;
	i=s;
	j=mid+1;
	k=s;
	while(i<=mid&&j<=e){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=e){
		temp[k++]=arr[j++];
	}
	for(int m=s;m<=e;m++){
		arr[m]=temp[m];
	}
	return ;
}

void mergeSort(int arr[],int s,int e){
	if(s>=e){
		return;
	}

	int mid=(s+e)/2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);
	merge(arr,s,e);
}

int main(){
	int arr[]={4,1,3,7,2,6,5};
	int n=sizeof(arr)/sizeof(int);
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}