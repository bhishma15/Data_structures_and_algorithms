/*
Given a Undirected Graph. Check whether it contains a cycle or not. 
*/

#include<bits/stdc++.h>

using namespace std;
 

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
    bool *vis=new bool[V];
    int *parent=new int[V];
    for(int i=0;i<V;i++){
        vis[i]=false;
    }
    for(int i=0;i<V;i++){
        if(vis[i]==false){
            queue<int> q;
            q.push(i);
            vis[i]=true;
            parent[i]=-1;
            while(!q.empty()){
                int s=q.front();
                q.pop();
                //[s]=true;
                for(int u:g[s]){
                    if(vis[u]==false)
                    {
                        q.push(u);
                         parent[u]=s;
                         vis[u]=true;
                    }else if(parent[s]!=u){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}