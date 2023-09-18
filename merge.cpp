#include<bits/stdc++.h>

#define F first
#define	S second
#define PB push_back
#define	MP make_pair
#define REP(i,a,b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void merge(int arr[],int a,int mid,int b){
	int size=b-a+1;
	int temp[size];
	int i=a,j=mid+1;
	int k=0;
	while(i<=mid&&j<=b){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}else{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=b){
		temp[k++]=arr[j++];
	}
	for(i=0;i<size;i++){
		arr[i+a]=temp[i];
	}
	return ;
}

void merge_sort(int arr[],int a,int b){
	//base case
	if(b>=a){
		return;
	}

	//recursive case
	int mid=(a+b)/2;
	merge_sort(arr,a,mid);
	merge_sort(arr,mid+1,b);
	merge(arr,a,mid,b);
	return;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	int arr[]={8,7,6,5,4,3,2,1};
	int n=8;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}