/*
You are given N pairs of numbers. In every pair, the first number\
 is always smaller than the second number. A pair (c, d) can follow \
 another pair (a, b) if b < c. Chain of pairs can be formed in this \
 fashion. You have to find the longest chain which can be formed from \
 e given set of pairs. 
*/

#include<bits/stdc++.h>

using namespace std;
 

bool my_fun(val a,val b){
    if(a.second == b.second) return a.first<b.first;
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n){
    sort(p,p+n,my_fun);
    int end = -1;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(p[i].first > end){
            end = p[i].second;
            cnt++;
        }
    }
    return cnt;
}
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}