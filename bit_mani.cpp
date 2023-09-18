#include<bits/stdc++.h>
using namespace std;

void solve(){
	//set implementation in bits{1,3,4,8}
	int x=0;
	x|=1<<1;
	x|=1<<3;
	x|=1<<4;
	x|=1<<8;
	

	//prit elements in set
	for(int i=0;i<32;i++){
		if(x&(1<<i))cout<<i<<" ";
	}
	cout<<endl;
	cout<<"size of set= "<<__builtin_popcount(x)<<endl;
	//set operations on x={1,3,4,8},y={3,6,8,9}
	int y=0,z=0;
	y|=1<<3;
	y|=1<<6;
	y|=1<<8;
	y|=1<<9;
	for(int i=0;i<32;i++){
		if(y&(1<<i))cout<<i<<" ";
	}
	cout<<endl;
	cout<<"size of set= "<<__builtin_popcount(y)<<endl;
	z=x&y;//intersection
	for(int i=0;i<32;i++){
		if(z&(1<<i))cout<<i<<" ";
	}
	cout<<endl;
	cout<<"size of set= "<<__builtin_popcount(z)<<endl;

	//union
	z=x|y;
	for(int i=0;i<32;i++){
		if(z&(1<<i))cout<<i<<" ";
	}
	cout<<endl;
	cout<<"size of set= "<<__builtin_popcount(z)<<endl;

	//difference
	z=x&~y;
	for(int i=0;i<32;i++){
		if(z&(1<<i))cout<<i<<" ";
	}
	cout<<endl;
	cout<<"size of set= "<<__builtin_popcount(z)<<endl;

	//negation
	x=~x;
	for(int i=0;i<32;i++){
		if(x&(1<<i))cout<<i<<" ";
	}
	cout<<endl;
	cout<<"size of set= "<<__builtin_popcount(x)<<endl;

	//iterating through subset
	int n=5;
	for(int b=0;b<(1<<n);b++){
		for(int i=0;i<n;i++){
			if(b&(1<<i)){
				cout<<i<<" ";
			}	
		}
		cout<<endl;
	}

	//process subsets with only k elements
	//iterating through subset
	n=5;
	int k=3;
	for(int b=0;b<(1<<n);b++){
		if(__builtin_popcount(b)==k){
			for(int i=0;i<n;i++){
			if(b&(1<<i)){
				cout<<i<<" ";
			}	
		}
		cout<<endl;
		}
	}
	//finding hamming distance
	//a="1101" b="0111"
	int a=0,b=0;
	a|=1<<0;
	a|=1<<2;
	a|=1<<3;

	b|=1<<0;
	b|=1<<1;
	b|=1<<2;

	cout<< __builtin_popcount(a^b) <<endl;
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	solve();
	return 0;
}