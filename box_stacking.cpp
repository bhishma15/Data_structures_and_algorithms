/*
You are given a set of N types of rectangular 3-D boxes, where the
 ith box has height h, width w and length l. You task is to create 
 a stack of boxes which is as tall as possible, but you can only 
 stack a box on top of another box if the dimensions of the 2-D base
  of the lower box are each strictly larger than those of the 2-D 
  base of the higher box. Of course, you can rotate a box so that 
  any side functions as its base.It is also allowable to use multiple 
  instances of the same type of box. You task is to complete the 
  function maxHeight which returns the height of the highest 
  possible stack so formed.

*/

#include<bits/stdc++.h>

using namespace std;

struct Box {
        int l,w,h;
    };
    
bool comp(Box a,Box b){
    if(a.l>b.l)
    return true;
    return false;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    
    
    Box dp[3*n];
    int ind=0;
    for(int i=0;i<n;i++){
        dp[ind].l=min(length[i],width[i]);
        dp[ind].w=max(length[i],width[i]);
        dp[ind].h=height[i];
        ind++;
        
        dp[ind].l=min(height[i],width[i]);
        dp[ind].w=max(height[i],width[i]);
        dp[ind].h=length[i];
        ind++;
        dp[ind].l=min(height[i],length[i]);
        dp[ind].w=max(height[i],length[i]);
        dp[ind].h=width[i];
        ind++;
    }
    n=3*n;
    sort(dp,dp+n,comp);
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=dp[i].h;
    }
    int mx=-1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(dp[j].l>dp[i].l&&dp[j].w>dp[i].w&&ans[i]<ans[j]+dp[i].h){
                ans[i]=ans[j]+dp[i].h;
                mx=max(mx,ans[i]);
            }
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