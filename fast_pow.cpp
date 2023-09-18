#include<bits/stdc++.h>

using namespace std;

int power(int a,int b){
	//base case
	if(b==0){
		return 1;
	}

	//recursive case
	int ans=power(a,b/2);
	ans*=ans;
	if(b%2==1){
		ans*=a;
	}
	return ans;
}
int main(){
	int a,b;
	cin>>a>>b;
	int ans=power(a,b);
	cout<<a<<"^"<<b<<"="<<ans<<endl;
	return 0;
}