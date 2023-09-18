#include<bits/stdc++.h>
using namespace std;
int coins[3]={1,3,4};
vector<int> dp(1000,-1);
//recursive_solution

int solve(int x){
	//base case
if (x <= 0) return 0;

if(dp[x]!=-1)
	return dp[x];
//recursive case
int best = INT_MAX;
for (auto c : coins) {
best = min(best, solve(x-c)+1);
}

return dp[x]=best;
}

//iterative solution
int solve_it(int n){
	int value[n+1],first[n];

	value[0]=0;
	for(int x=1;x<=n;x++){
		value[x]=INT_MAX;
		for(auto c:coins){
			if((x-c)>=0&&(value[x-c]+1)<value[x]){
				value[x]=value[x-c]+1;
				first[x]=c;
			}
		}
	}
	while(n>0){
		cout<<first[n]<<" ";
		n -= first[n];
	}
	return value[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	
	int ans=solve_it(5);
	cout<<ans<<endl;
	return 0;
}