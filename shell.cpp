#include<bits/stdc++.h>
using namespace std;

void shell_sort(int arr[],int n){
	for(int h=4;h>0;h/=2){
		for(int i=h;i<n;i++){
			int j=i;
			int key=arr[i];
			while(j>=h&&arr[j-h]>key){
				swap(arr[j],arr[j-h]);
				j-=h;
			}
			arr[j]=key;
		}
	}
}

int main(){
	int arr[]={10,9,8,7,6,5,4,3,2,1};
	int n=10;
	shell_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}