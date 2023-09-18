#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b){
	//BASE CONDITION
    if(b==0)
    	return 1;

	//RECURSIVE CALL
	int ans=a*solve(a,b-1);
	return ans;
}

int main(){
	int a,b;
	a=3;
	b=4;
	int ans=solve(a,b);
	cout<<ans<endl;
	return 0;
} 