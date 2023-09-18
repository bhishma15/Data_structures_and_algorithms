#include<bits/stdc++.h>
#define N 4
using namespace std;

//for bellman ford
vector<tuple<int,int,int>> edges;

//for dijktras
vector<pair<int,int > > adj[N];
	

void dijktra(int x){
	int n=4;
	int dist[n];
	for(int i=1;i<n;i++){
		dist[i]=INT_MAX;
	}
	bool processed[n]={false};
	dist[x]=0;
	priority_queue<pair<int,int> > q;
	q.push({0,x});
	while(!q.empty()){
		int a=q.top().second;
		q.pop();
		if(processed[a])continue;
		processed[a]=true;
		for(auto u:adj[a]){
			int b=u.first;
			int w=u.second;
			dist[b]=min(dist[b],dist[a]+w);
			q.push({-dist[b],b});
		}
	}
	cout<<"node dist"<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<"    "<<dist[i]<<endl;
	}
}

void bellman_ford(int x,int n){
	int dist[n];
	for(int i=1;i<=n;i++){
		dist[i]=INT_MAX;
	}
	dist[x]=0;
	for(int i=1;i<n;i++){
		for(auto e:edges){
			int a,b,w;
			tie(a,b,w)=e;
			dist[b]=min(dist[b],dist[a]+w);
		}
	}

	//print distances
	cout<<"Node dist"<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<"     "<<dist[i]<<endl;
	}
	return ;
}

//all pair shortest path
void floyd_warshall(){
	int adj_mat[N+1][N+1];
	memset(adj_mat,0,sizeof(adj_mat));
	adj_mat[1][2]=5;
	adj_mat[2][3]=7;
	adj_mat[2][4]=6;
	adj_mat[3][4]=5;
	adj_mat[4][1]=2;

	adj_mat[2][1]=5;
	adj_mat[3][2]=7;
	adj_mat[4][2]=6;
	adj_mat[4][3]=5;
	adj_mat[1][4]=2;

	int dist[N+1][N+1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j){
				dist[i][j]=0;
			}
			else if(adj_mat[i][j]){
				dist[i][j]=adj_mat[i][j];}
						else{
				dist[i][j]=INT_MAX;
			}
		}
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	edges.push_back({1,2,5});
	edges.push_back({2,3,7});
	edges.push_back({2,4,6});
	edges.push_back({3,4,5});
	edges.push_back({4,1,2});
	//bellman_ford(1,4);

	adj[1].push_back({2,5});
	adj[2].push_back({1,5});
	adj[2].push_back({3,7});
	adj[2].push_back({4,6});
	adj[3].push_back({4,5});
	adj[4].push_back({1,2});

	adj[3].push_back({2,7});
	adj[4].push_back({2,6});
	adj[4].push_back({3,5});
	adj[1].push_back({4,2});
	//dijktra(1);
	floyd_warshall();
	return 0;
}