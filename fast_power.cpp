#include<bits/stdc++.h>
using namespace std;

int fastPower(int a,int b){
	if(b==0)
		return 1;
	int ans;
	if(b&1){
		ans=fastPower(a,(b-1)/2);
		ans =ans*ans;
		return a*ans;
	}
	else{
		ans=fastPower(a,b/2);
		ans*=ans;
		return ans;
	}
}
int power(int a,int b){
	if(b==0){
		return 1;
	}
	
		return a*solve(a,b-1);
	
}

int main(){
	int a,b;
	a=3;
	b=4;
	int ans=fastPower(a,b);
	cout<<ans<<endl;
	return 0;
} 