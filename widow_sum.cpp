#include<bits/stdc++.h>

using namespace std;
//finding sum of window size elements
void solve(int arr[],int n,int w){
	int b[n];
	int sum=0;
	for(int i=0;i<w;i++){
		sum+=arr[i];
	}
	b[0]=sum;
	for(int i=w;i<n;i++){
		sum=sum+arr[i]-arr[i-w];
		b[i-w+1]=sum;
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
}

int main(){
	//write your code here
	int n,w;
	cin>>n>>w;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	solve(arr,n,w);
	cout<<endl;
}