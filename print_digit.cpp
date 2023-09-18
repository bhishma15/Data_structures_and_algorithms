#include<bits/stdc++.h>
using namespace std;
string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void solve(int n){
	if(n==0){
		return;
	}
	solve(n/10);
	cout<<arr[n%10]<<" ";
}

int main(){
	int n;
	cin>>n;
	solve(n);
	cout<<endl;
	return 0;
} 