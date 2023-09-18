#include<bits/stdc++.h>
using namespace std;

int solve(){
	

	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int coins[]={1,3,4};
int solve(int n){
	int count[n+1];
	count[0]=1;
	for(int x=1;x<=n;x++){
		count[x]=0;
		for(auto c:coins){
			if((x-c)>=0){
				count[x]+=count[x-c];
			}
		}
	}	
	return count[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	int ans=solve(5);
	cout<<ans<<endl;
	return 0;
}