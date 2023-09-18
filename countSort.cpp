#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int n,int k){
	int c[k+1],t[n];
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		c[arr[i]]++;
	}
	for(int i=1;i<=k;i++){
		c[i]+=c[i-1];
	}

	for(int i=0;i<n;i++){
		t[c[arr[i]-1]]=arr[i];
	}
	for(int i=0;i<n;i++){
		arr[i]=t[i];
	}
	return;
}

int main(){
	int arr[]={1,4,2,5,3,6};
	int n=6;
	int k=10;
	countSort(arr,n,k);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}