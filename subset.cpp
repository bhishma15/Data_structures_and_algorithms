#include<bits/stdc++.h>
using namespace std;

vector<int> subset;
//finding subsets with recursion
void subset1(int k,int n){
	if(k==n){
		for(auto x:subset){
			cout<<x<<" ";
		}
		cout<<endl;
	}else{
		subset1(k+1,n);
		subset.push_back(k);
		subset1(k+1,n);
		subset.pop_back();
	}

	return;
}

//finding subsets using bits
void subset2(int n){
	for(int a=0;a<(1<<n);a++){
		vector<int> subset;
		for(int j=0;j<n;j++){
			if(a&(1<<j)){
				subset.push_back(j);
			}
		}
		for(auto x:subset){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	
	subset1(0,3);

	return 0;
}