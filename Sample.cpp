#include<bits/stdc++.h>
using namespace std;

void fun(int **arr,int m,int n){
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return;
}

int main(){
	vector<int> a[3];
	a[0]={2,1,3};
	a[1]={5,1,3};
	a[2]={2,4,7};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}