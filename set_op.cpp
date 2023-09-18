#include<bits/stdc++.h>
using namespace std;

void makeset(int arr[],int n){
	for(int i=0;i<n;i++){
		arr[i]=i;
	}
	return;
}

int find_set(int arr[],int n,int x){
	if(x<0||x>=n){
		return -1;
	}
	if(arr[x]==x){
		return x;
	}
	else{
		return find_set(arr,n,arr[x]);
	}
}

void union_set(int arr[],int n,int root1,int root2){
	if(find_set(arr,n,root1)==find_set(arr,n,root2)){
		return ;
	}
	if(root1<0||root2<0||root1>=n||root2>=n){
		return ;
	}
	arr[root1]=root2;
}

int main(){
	int arr[10];
	int n=10;
	makeset(arr,n);
	union_set(arr,n,3,4);
	cout<<find_set(arr,n,3)<<endl;
}