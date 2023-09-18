/*
There are N piles of coins each containing  Ai (1<=i<=N) coins.  \
Now, you have to adjust the number of coins in each pile such that \
for any two pile, if a be the number of coins in first pile and b is\
the number of coins in second pile then |a-b|<=K. In order to do that \
you can remove coins from different piles to decrease the number of \
oins in those piles but you cannot increase the number of coins in \
a pile by adding more coins. Now, given a value of N and K, along \
with the sizes of the N different piles you have to tell the minimum \
number of coins to be removed in order to satisfy the given \
condition.3
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t, n, k;
	cin >> t;
	while(t--) {
	 
	    cin >> n >> k;
	    vector <int> piles(n);
	    for(int i = 0; i < n;  i++)
	        cin >> piles[i];
	    sort(piles.begin(), piles.end());
	    int ans = INT_MAX;
	    int prevSum = 0, curSum = 0;
	    for(int i = 0; i < n; i++) {
	        prevSum += i < 1 ? 0 : piles[i-1];
	        curSum = 0;
	        for(int j = n-1; j > i; j--) {
	            if(piles[j] - piles[i] <= k)
	                break;
	            curSum += piles[j] - piles[i] - k;
	        }
	        ans = min(ans, curSum + prevSum);
	    }
	    cout << ans << endl;
	}
	
	return 0;
}