/*
Given an array having both positive and negative integers.\
 The task is to compute the length of the largest subarray \
 with sum 0.
*/

#include<bits/stdc++.h>

using namespace std;
 


int maxLen(int A[], int n)
{
    // Your code here
    map<int,int> mp;
    int sum=0;
    int x=0,y=0;
    int mx=0;
    mp.insert({sum,-1});
    for(int i=0;i<n;i++){
        sum += A[i];
        if(mp.find(sum)!=mp.end()){
            y=i;
            x=mp.at(sum);
            mx=max(mx,y-x);
            mp.insert({sum,i});
        }else{
            mp.insert({sum,i});
        }
    }
    return mx;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}