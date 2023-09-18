#include<bits/stdc++.h>
using namespace std;
int fib(int n){
	//base condition
	if(n==0||n==1)
		return n;
	//recursive call
	int ans=fib(n-1)+fib(n-2);
	return ans;
}
int main(){
	int n;
	cin>>n;
	int ans=fib(n);
	cout<<"fibonacci of "<<n<<" = "<<ans<<endl;
}
