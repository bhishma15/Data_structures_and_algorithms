#include<bits/stdc++.h>
#define N 100
using namespace std;

// ds for dfs
vector<int> adj[N];
bool visited[N]={false};

//ds for bfs
queue<int> q;
bool visit[N]={false};
int dist[N];

//dfs graph traversal 
void dfs(int s){
	if(visited[s])return;
	cout<<s<<" ";
	visited[s]=true;
	for(auto u:adj[s]){
		dfs(u);
	}
	return ;
}

void bfs(int s){
	visited[s]=true;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(auto u:adj[x]){
			if(visit[u])continue;
			visit[u]=true;
			dist[u]=dist[x]+1;
			q.push(u);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here

	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(4);
	adj[4].push_back(1);
	dfs(1);
	cout<<endl;
	bfs(2);
	cout<<endl;
	return 0;
}