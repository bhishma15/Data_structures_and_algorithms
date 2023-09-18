#include<bits/stdc++.h>
using namespace std;

int convert(string str,int n,int base){
	if(n==0){
		return 0;
	}

	return (int(str[n-1])-48)*base+convert(str,n-1,base*10);
}
int main(){
	string str="678";
	int ans =convert(str,str.length(),1);
	cout<<ans<<endl;
	return 0;
} 