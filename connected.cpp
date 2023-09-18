#include<bits/stdc++.h>
using namespace std;

bool isConnected(vector<int> adj[],int N){
	bool *vis=new bool[N];
	for(int i=0;i<N;i++){
		vis[i]=false;
	}
	queue<int> q;
	q.push(0);
	vis[0]=true;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(auto u:adj[s]){
			if(vis[u])continue;
			vis[u]=true;
			q.push(u);
		}
	}
	for(int i=0;i<N;i++){
		if(!vis[i])return false;
	}
	return true;
}

int connectedCompo(vector<int> adj[],int N){
	bool *vis=new bool[N];
	for(int i=0;i<N;i++){
		vis[i]=false;
	}
	int count=0;
	queue<int> q;
	q.push(0);
	vis[0]=true;
	while(1){
		count++; 
		while(!q.empty()){
			int s=q.front();
			q.pop();
			for(auto u:adj[s]){
				if(vis[u])continue;
				vis[u]=true;
				q.push(u);
			}
		}
		bool flg=true;
		for(int i=0;i<N;i++){
			if(!vis[i]){
				flg=false;
				q.push(i);
				break;
			}
		}
		if(flg)
			return count;
	}
}
int main(){
	int n,m;
	cout<<"Enter the no of vertices and edges"<<endl;
	cin>>n>>m;
	vector<int> adj[n];
	cout<<"enter the edges"<<endl;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	/*if(isConnected(adj,n)){
		cout<<"Graph is connected"<<endl;
	}else{
		cout<<"Graph is not connected"<<endl;
	}*/

	int ans=connectedCompo(adj,n);
	cout<<"No of connected components "<<ans<<endl;
}