#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr,int n){
	//BASE CONDITION
	if(n==1)
		return true;

	//RECURSIVE CALL
	if(arr[0]<arr[1]&& isSorted(arr+1,n-1)){
		return true;
	}
	return false;
}

int main(){
	int arr[]={2,3,15,7,10};
	int n=5;
	if(isSorted(arr,n)){
		cout<<"Array is sorted"<<endl;
	}
	else{
		cout<<"Array not sorted"<<endl;
	}
	return 0;
} 