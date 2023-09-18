/*
Given a connected undirected graph. Perform a Depth First Traversal \
of the graph.
*/
#include<bits/stdc++.h>

using namespace std;
 

void dfs(vector<int> g[],bool vis[],int s,vector<int>& v){
    if(vis[s])return;
    v.push_back(s);
    vis[s]=true;
    for(auto u:g[s]){
        solve(g,vis,u,v);
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    // Your code here
   vector<int> v;
   vector<bool> vis(n,0);
   dfs(g,vis,0,v);
   return v;
    
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}