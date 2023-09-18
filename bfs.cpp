#include<bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    vector<bool> vis(n,0);
    vector<int> v;
    
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        v.push_back(s);
        for(int u:g[s]){
            if(vis[u])continue;
            vis[u]=true;
            q.push(u);
        }
    }
    return v;
}

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int v,e;
  cin>>v>>e;
  vector<int> adj[v];
  for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  vector<int> v=bfs(adj,v);
  return 0;
}