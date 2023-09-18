
#include<bits/stdc++.h>
using namespace std;

int ps[100],ss[100],ts[100],ms[100];

int query(int *arr,int s,int e,int l,int r,int index){
	if(s==e){
		ps[s]=arr[s];
		ss[s]=arr[s];
		ts[s]=arr[s];
		ms[s]=arr[s];
		return ms[s];
	}


	//complte overlap
	if(l==s&&r==e){
		return ms[index];
	}

	//partial overlap
	int mid=(s+e)/2;
	int left=query(arr,s,mid,l,r,2*index);
	int right=query(arr,mid+1,e,l,r,2*index+1);
	ms[index]=max(max(left,right),ss[2*index]+ps[2*index+1]);
	return ms[index];
}
/*int build_tree(int *arr,int s,int e,int index){
	//base case
	

	//recursive case
	int mid=(s+e)/2;
	build_tree(arr,s,mid,2*index);
	build_tree(arr,mid+1,e,2*index+1);
	ms[index]=max(max(ms[2*index+1],ms[2*index+1]),ss[2*index]+ps[2*index+1]);
	return ;
}*/

int main(){
	int arr[]={1,3,-2,5,4};
	int n=5;
	int ans=query(arr,0,4,3,4,1);
	cout<<ans<<endl;
	return 0;
}