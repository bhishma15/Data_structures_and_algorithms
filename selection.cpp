#include<iostream>

using namespace std;

void selection(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int m=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[m]){
				m=j;
			}
		}
		swap(arr[m],arr[i]);
	}
	return;
}

int main(){
	int arr[]={5,1,2,4,3};
	selection(arr,5);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int a,b;
	a=10;
	b=20;
	sample(a,b);
	cout<<a<<" "<<b<<endl;
}