#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll fact(ll n){
	//base condition
	if(n==0)
		return 1;
	//recursive call
	ll ans=n*fact(n-1);
	return ans;
}
int main(){

	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll ans=fact(i);
	    cout<<"factorial of "<<i<<" = "<<ans<<endl;
	}
	
}
