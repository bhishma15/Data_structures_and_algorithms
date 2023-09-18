#include<bits/stdc++.h>
#define N 5
using namespace std;

int solve(int grid[N][N]){
	int sum[N+1][N+1];
	for(int i=0;i<=N;i++){
		sum[i][0]=0;
		sum[0][i]=0;
	}
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			sum[x][y]=max(sum[x-1][y],sum[x][y-1])+grid[x-1][y-1];
		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	return sum[N][N];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	int grid[N][N]={
		{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}
	};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	int ans=solve(grid);
	cout<<ans<<endl;
	return 0;
}