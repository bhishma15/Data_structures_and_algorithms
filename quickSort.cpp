#include<bits/stdc++.h>

using namespace std;

int partition(int arr[],int low,int high){
	int piv=high;
	int i=low-1,j=low;
	while(j<piv){
		if(arr[j]<arr[piv]){
			i++;
			swap(arr[i],arr[j]);
		}
		j++;
	}
	swap(arr[i+1],arr[piv]);
	return i+1;
}


void quickSort(int arr[],int low,int high){
	if(low<high){
		int p=partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}


int main(){
	int arr[]={6,1,4,2,5,3};
	int n=6;
	quickSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}