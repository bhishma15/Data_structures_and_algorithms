/*We are given the prices of k
products over n days, and we want to buy each product exactly once. However,
we are allowed to buy at most one product in a day. What is the minimum total
price?*/
#include<bits/stdc++.h>
#define k 3
#define n 8
using namespace std;

int buy_products(int price[k][n]){
	
	int total[1<<k][n];

	for (int x = 0; x < k; x++) {
	total[1<<x][0] = price[x][0];
	}
	for (int d = 1; d < n; d++) {
		for (int s = 0; s < (1<<k); s++) {
			total[s][d] = total[s][d-1];
			for (int x = 0; x < k; x++) {
				if (s&(1<<x)) {
					total[s][d] = min(total[s][d],total[s^(1<<x)][d-1]+price[x][d]);
				}
			}
		}
	}
	return total[(1<<k)-1][n-1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here

	int arr[3][8];

	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int ans=buy_products(arr);
	cout<<ans<<endl;
	return 0;
}