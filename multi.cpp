#include<bits/stdc++.h>
using namespace std;

int solve(int a,int count){
	if(count==0){
		return 0;
	}

	return a+solve(a,count-1);
}

int main(){
	int a,b;
	cin>>a>>b;
	if(a<0&&b<0){
		a=-a;
		b=-b;
	}
	if(a>0&&b<0){
		b=-b;
		a=-a;
	}
	int ans=solve(a,b);
	cout<<"product of "<<a<<" and "<<b<<" = "<<ans<<endl;
	return 0;
} 